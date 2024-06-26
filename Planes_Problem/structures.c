#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function for queue

void displayQueue(Queue* queue) {
    Node* current = queue->front;
    while (current != NULL) {
        printf("Tail Number: %s\n", current->plane.tailNumber);
        printf("Destination: %s\n", current->plane.destination);
        current = current->next;
    }
}

void displayStack(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        printf("Tail Number: %s\n", current->plane.tailNumber);
        printf("Destination: %s\n", current->plane.destination);
        current = current->next;
    }
}

Queue* initializeQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire pour la queue.\n");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void freeQueue(Queue* queue) {
    while (!isQueueEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

void enqueue(Queue* queue, Plane plane) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire pour un nouveau noeud.\n");
        exit(EXIT_FAILURE);
    }
    newNode->plane = plane;
    newNode->next = NULL;

    if (isQueueEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->size++;
}

Plane dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        fprintf(stderr, "La queue est vide, impossible de dépiler.\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = queue->front;
    Plane plane = temp->plane;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;
    if (isQueueEmpty(queue)) {
        queue->rear = NULL;
    }
    return plane;
}

int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

int searchInQueue(Queue* queue, char* tailNumber) {
    Node* current = queue->front;
    int position = 1;
    while (current != NULL) {
        if (strcmp(current->plane.tailNumber, tailNumber) == 0) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; 
}

// Fonctions pour les stacks

Stack* initializeStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire pour la stack.\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void freeStack(Stack* stack) {
    while (!isStackEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

void push(Stack* stack, Plane plane) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire pour un nouveau noeud.\n");
        exit(EXIT_FAILURE);
    }
    newNode->plane = plane;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

Plane pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        fprintf(stderr, "La stack est vide, impossible de dépiler.\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = stack->top;
    Plane plane = temp->plane;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return plane;
}

int isStackEmpty(Stack* stack) {
    return stack->top == NULL;
}

int searchInStack(Stack* stack, char* tailNumber) {
    Node* current = stack->top;
    int position = 1;
    while (current != NULL) {
        if (strcmp(current->plane.tailNumber, tailNumber) == 0) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}

// Fonctions pour les linked lists

LinkedList* initializeList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire pour la liste chaînée.\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void freeList(LinkedList* list) {
    while (list->head != NULL) {
        removeFromBeginning(list);
    }
    free(list);
}

void insertAtBeginning(LinkedList* list, Plane plane) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire pour un nouveau noeud.\n");
        exit(EXIT_FAILURE);
    }
    newNode->plane = plane;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void removeFromBeginning(LinkedList* list) {
    if (list->head == NULL) {
        fprintf(stderr, "La liste chaînée est vide, impossible de supprimer.\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}

void displayList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("Tail number: %s, Destination: %s\n", current->plane.tailNumber, current->plane.destination);
        current = current->next;
    }
}

int searchInList(LinkedList* list, char* tailNumber) {
    Node* current = list->head;
    int position = 1;
    while (current != NULL) {
        if (strcmp(current->plane.tailNumber, tailNumber) == 0) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; 
}
