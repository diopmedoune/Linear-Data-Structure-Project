#include "taskControl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void executeDurationTest() {
    clock_t start = clock();

    clock_t stop = clock();

    float  time =  (double)(stop-start)/CLOCKS_PER_SEC;
}

// Global variable to track task IDs
static int next_task_id = 1;

int generateId() {
    next_task_id = next_task_id;
    return next_task_id;
}

TaskQueue *initializeTaskQueue() {
    TaskQueue *queue = (TaskQueue *)malloc(sizeof(TaskQueue));
    if (queue == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    queue->first = NULL;
    queue->last = NULL;
    queue->size = 0;
    return queue;
}

void freeTaskQueue(TaskQueue *queue) {
    while (queue->first != NULL) {
        Task *temp = queue->first;
        queue->first = queue->first->next;
        free(temp);
    }
    free(queue);
}

void enqueueTask(TaskQueue *queue, Task *task) {
    task->id = next_task_id++;
    task->status = 0;

    task->next = NULL;
    if (queue->last == NULL) {
        queue->first = task;
    } else {
        queue->last->next = task;
    }
    queue->last = task;
    queue->size++;
}

Task *dequeueTask(TaskQueue *queue) {
    if (queue->first == NULL) {
        return NULL;
    }
    Task *task = queue->first;
    queue->first = queue->first->next;
    if (queue->first == NULL) {
        queue->last = NULL;
    }
    queue->size--;
    return task;
}

Task *createTask(const char *name, const char *description, int priority, const char *creation_date, const char *due_date) {
    Task *task = (Task *)malloc(sizeof(Task));
    if (task == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    task->id = generateId();
    strncpy(task->name, name, sizeof(task->name) - 1);
    task->name[sizeof(task->name) - 1] = '\0';
    strncpy(task->description, description, sizeof(task->description) - 1);
    task->description[sizeof(task->description) - 1] = '\0';
    task->priority = priority;
    task->status = 0;
    strncpy(task->creation_date, creation_date, sizeof(task->creation_date) - 1);
    task->creation_date[sizeof(task->creation_date) - 1] = '\0';
    strncpy(task->due_date, due_date, sizeof(task->due_date) - 1);
    task->due_date[sizeof(task->due_date) - 1] = '\0';
    task->next = NULL;
    return task;
}

void displayTask(const Task *task) {
    printf("Task ID: %d\n", task->id);
    printf("Name: %s\n", task->name);
    printf("Description: %s\n", task->description);
    printf("Priority: %d\n", task->priority);
    printf("Status: %d\n", task->status);
    printf("Creation Date: %s\n", task->creation_date);
    printf("Due Date: %s\n", task->due_date);
    printf("\n");
}

void displayTaskQueue(const TaskQueue *queue) {
    if (queue->first == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Task *current = queue->first;
    while (current != NULL) {
        displayTask(current);
        current = current->next;
    }
}


// Rechercher une tâche par son nom
Task *searchTaskByName(const TaskQueue *queue, const char *name) {
    Task *current = queue->first;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Si la tâche n'est pas trouvée
}