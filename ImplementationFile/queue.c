#include <stdio.h>
#include <stdlib.h>

// Structure de la file
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Initialisation de la file
Queue* initQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Vérifier si la file est vide
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Ajouter un élément à la file (enqueue)
void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }

    queue->rear = newNode;
    queue->size++;
}

// Retirer un élément de la file (dequeue)
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("La file est vide, impossible de retirer un élément.\n");
        return -1; 
    }

    int removedValue = queue->front->data;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);

    queue->size--;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return removedValue;
}

// Afficher la file
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("La file est vide.\n");
        return;
    }

    printf("Contenu de la file : ");
    Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Libérer la mémoire utilisée par la file
void freeQueue(Queue* queue) {
    Node* current = queue->front;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(queue);
}

// Fonction principale
int main() {
    Queue* queue = initQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    displayQueue(queue);

    printf("Élément retiré de la file : %d\n", dequeue(queue));
    printf("Élément retiré de la file : %d\n", dequeue(queue));

    displayQueue(queue);

    enqueue(queue, 50);
    enqueue(queue, 60);

    displayQueue(queue);

    freeQueue(queue);

    return 0;
}