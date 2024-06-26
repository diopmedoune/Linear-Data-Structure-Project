#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

// Function to calculate the memory used by the queue
void testQueueMemory(int num_planes) {
    Queue* queue = initializeQueue();
    size_t initial_memory, final_memory;
    size_t total_memory = 0;

    initial_memory = sizeof(Queue) + queue->size * sizeof(Node);

    for (int i = 0; i < num_planes; i++) {
        Plane plane = {"ABC001", "Destination"};
        enqueue(queue, plane);
    }

    final_memory = sizeof(Queue) + queue->size * sizeof(Node);

    total_memory = final_memory - initial_memory;

    printf("Memory used for enqueuing %d planes = %lu bytes\n", num_planes, total_memory);
    freeQueue(queue);
}

// Function to calculate the memory used by the stack
void testStackMemory(int num_planes) {
    Stack* stack = initializeStack();
    size_t initial_memory, final_memory;
    size_t total_memory = 0;

    initial_memory = sizeof(Stack) + stack->size * sizeof(Node);

    for (int i = 0; i < num_planes; i++) {
        Plane plane = {"ABC001", "Destination"};
        push(stack, plane);
    }

    final_memory = sizeof(Stack) + stack->size * sizeof(Node);

    total_memory = final_memory - initial_memory;

    printf("Memory used to push %d planes = %lu bytes\n", num_planes, total_memory);
    freeStack(stack);
}

// Function to calculate the memory used by the linked list
void testListMemory(int num_planes) {
    LinkedList* list = initializeList();
    size_t initial_memory, final_memory;
    size_t total_memory = 0;

    initial_memory = sizeof(LinkedList) + list->size * sizeof(Node);

    for (int i = 0; i < num_planes; i++) {
        Plane plane = {"ABC001", "Destination"};
        insertAtBeginning(list, plane);
    }

    final_memory = sizeof(LinkedList) + list->size * sizeof(Node);

    total_memory = final_memory - initial_memory;

    printf("Memory used to insert %d planes = %lu bytes\n", num_planes, total_memory);
    freeList(list);
}
