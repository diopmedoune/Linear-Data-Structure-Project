#ifndef STRUCTURES_H
#define STRUCTURES_H

#define MAX_PLANES 100
#define NUM_PLANES 10000

typedef struct Plane {
    char tailNumber[10];
    char destination[50];
} Plane;

typedef struct Node {
    Plane plane;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

typedef struct Stack {
    Node* top;
    int size;
} Stack;

typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

Queue* initializeQueue();
void freeQueue(Queue* queue);
void enqueue(Queue* queue, Plane plane);
Plane dequeue(Queue* queue);
int isQueueEmpty(Queue* queue);
void displayQueue(Queue* queue);
int searchInQueue(Queue* queue, char tailNumber[]);

Stack* initializeStack();
void freeStack(Stack* stack);
void push(Stack* stack, Plane plane);
Plane pop(Stack* stack);
int isStackEmpty(Stack* stack);
void displayStack(Stack* stack);
int searchInStack(Stack* stack, char tailNumber[]);

LinkedList* initializeList();
void freeList(LinkedList* list);
void insertAtBeginning(LinkedList* list, Plane plane);
void removeFromBeginning(LinkedList* list);
void displayList(LinkedList* list);
int searchInList(LinkedList* list, char tailNumber[]);

#endif
