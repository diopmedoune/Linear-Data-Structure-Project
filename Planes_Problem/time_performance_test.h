#ifndef TIME_PERFORMANCE_TEST_H
#define TIME_PERFORMANCE_TEST_H

#include "structures.h"

double measure_time(void (*function)(int, void*), int repetitions, int num_planes, void* data_structure);

void enqueue_function(int num_planes, Queue* queue);
void dequeue_function(int num_planes, Queue* queue);
void push_function(int num_planes, Stack* stack);
void pop_function(int num_planes, Stack* stack);
void insert_function(int num_planes, LinkedList* list);
void remove_function(int num_planes, LinkedList* list);

#endif 
