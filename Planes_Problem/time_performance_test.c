#include <stdio.h>
#include <time.h>
#include "time_performance_test.h"

double measure_time(void (*function)(int, void*), int repetitions, int num_planes, void* data_structure) {
    clock_t start, end;
    double cpu_time_used = 0.0;

    start = clock();
    for (int i = 0; i < repetitions; ++i) {
        function(num_planes, data_structure);
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used / repetitions;
}

void enqueue_function(int num_planes, Queue* queue) {
    Plane plane = {"ABC001", "Pakistan"};

    for (int i = 0; i < num_planes; ++i) {
        enqueue(queue, plane);
    }
}

void dequeue_function(int num_planes, Queue* queue) {
    for (int i = 0; i < num_planes; ++i) {
        dequeue(queue);
    }
}

void push_function(int num_planes, Stack* stack) {
    Plane plane = {"ABC001", "Pakistan"};

    for (int i = 0; i < num_planes; ++i) {
        push(stack, plane);
    }
}

void pop_function(int num_planes, Stack* stack) {
    for (int i = 0; i < num_planes; ++i) {
        pop(stack);
    }
}

void insert_function(int num_planes, LinkedList* list) {
    Plane plane = {"ABC001", "Pakistan"};

    for (int i = 0; i < num_planes; ++i) {
        insertAtBeginning(list, plane);
    }
}

void remove_function(int num_planes, LinkedList* list) {
    for (int i = 0; i < num_planes; ++i) {
        removeFromBeginning(list);
    }
}
