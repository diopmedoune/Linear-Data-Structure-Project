#ifndef TASK_CONTROL_H
#define TASK_CONTROL_H

typedef struct Task {
    int id;
    char name[50];
    char description[100];
    int priority; 
    int status; 
    char creation_date[50];
    char due_date[50];
    struct Task *next;
} Task;

typedef struct {
    Task *first;
    Task *last;
    int size;
} TaskQueue;

TaskQueue *initializeTaskQueue();
void freeTaskQueue(TaskQueue *queue);
void enqueueTask(TaskQueue *queue, Task *task);
Task *dequeueTask(TaskQueue *queue);
Task *createTask(const char *name, const char *description, int priority, const char *creation_date, const char *due_date);
void displayTask(const Task *task);
void displayTaskQueue(const TaskQueue *queue);
Task *searchTaskByName(const TaskQueue *queue, const char *name);

#endif
