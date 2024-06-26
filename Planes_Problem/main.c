#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structures.h"
#include "time_performance_test.h"
#include "memory_performance_test.h"

#define MAX_NUM_PLANES 10000
#define STEP_SIZE 1000

int main() {

    Queue* queue = initializeQueue();
    Stack* stack = initializeStack();
    LinkedList* list = initializeList();

    double queue_enqueue_times[MAX_NUM_PLANES / STEP_SIZE];
    double queue_dequeue_times[MAX_NUM_PLANES / STEP_SIZE];
    double stack_push_times[MAX_NUM_PLANES / STEP_SIZE];
    double stack_pop_times[MAX_NUM_PLANES / STEP_SIZE];
    double list_insert_times[MAX_NUM_PLANES / STEP_SIZE];
    double list_remove_times[MAX_NUM_PLANES / STEP_SIZE];

    int idx = 0;
    for (int num_planes = STEP_SIZE; num_planes <= MAX_NUM_PLANES; num_planes += STEP_SIZE) {
        printf("\nPerformance tests for %d planes:\n", num_planes);

        // Store the average times for plotting
        queue_enqueue_times[idx] = measure_time((void (*)(int, void*))enqueue_function, 100, num_planes, queue);
        queue_dequeue_times[idx] = measure_time((void (*)(int, void*))dequeue_function, 100, num_planes, queue);
        stack_push_times[idx] = measure_time((void (*)(int, void*))push_function, 100, num_planes, stack);
        stack_pop_times[idx] = measure_time((void (*)(int, void*))pop_function, 100, num_planes, stack);
        list_insert_times[idx] = measure_time((void (*)(int, void*))insert_function, 100, num_planes, list);
        list_remove_times[idx] = measure_time((void (*)(int, void*))remove_function, 100, num_planes, list);

        idx++;
    }

    freeQueue(queue);
    freeStack(stack);
    freeList(list); 

    printf("Enqueue times --> : ");
    for (int i = 0; i < idx; i++) {
        printf("%.8f ", queue_enqueue_times[i]);
    }

    printf("\nDequeue times --> : ");
    for (int i = 0; i < idx; i++) {
        printf("%.8f ", queue_dequeue_times[i]);
    }

    printf("\nPush times --> : ");
    for (int i = 0; i < idx; i++) {
        printf("%.8f ", stack_push_times[i]);
    }

    printf("\nPop times --> : ");
    for (int i = 0; i < idx; i++) {
        printf("%.8f ", stack_pop_times[i]);
    }

    printf("\nInsert times --> : ");
    for (int i = 0; i < idx; i++) {
        printf("%.8f ", list_insert_times[i]);
    }

    printf("\nRemove times --> : ");
    for (int i = 0; i < idx; i++) {
        printf("%.8f ", list_remove_times[i]);
    }

    // Memory performance test
    printf("\n\n==== Memory performance tests ===\n");

    printf("\n---Queue---\n");
    testQueueMemory(1000);
    testQueueMemory(2000);
    testQueueMemory(3000);
    testQueueMemory(4000);

    printf("\n---Stack---\n");
    testStackMemory(1000);
    testStackMemory(2000);
    testStackMemory(3000);
    testStackMemory(4000);
    
    printf("\n---Linked list---\n");
    testListMemory(1000);
    testListMemory(2000);
    testListMemory(3000);
    testListMemory(4000);

    return 0;
}
