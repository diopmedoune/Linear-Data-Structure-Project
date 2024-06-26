#include <stdio.h>
#include <stdlib.h>
#include "listechainee.h"

LinkedList* initializeList() {
    LinkedList *linkedList = malloc(sizeof(*linkedList));
    if (linkedList == NULL) {
        exit(0);
    }
    linkedList->head = NULL;
    return linkedList;
}

void insertNode(LinkedList *linkedList, int data) {
    Node *newNode = malloc(sizeof(*newNode));
    if (linkedList == NULL || newNode == NULL) {
        exit(0);
    }
    newNode->data = data;
    newNode->next = linkedList->head;
    linkedList->head = newNode;
}

Node* findPreviousNode(LinkedList *linkedList, int data) {
    if (linkedList == NULL) {
        exit(0);
    }
    Node *current = linkedList->head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("La valeur recherchée n'est pas dans la liste.\n");
    }
    return current;
}

void deleteNode(LinkedList *linkedList, int data) {
    if (linkedList == NULL) {
        exit(0);
    }
    if (linkedList->head != NULL && linkedList->head->data == data) {
        Node *nodeToDelete = linkedList->head;
        linkedList->head = linkedList->head->next;
        free(nodeToDelete);
    } else {
        Node *previous = findPreviousNode(linkedList, data);
        Node *temp1 = previous;
        Node *temp2 = previous->next;
        temp1->next = temp2->next;
        free(temp2);
    }
}

void displayList(LinkedList *linkedList) {
    if (linkedList == NULL) {
        exit(0);
    }
    Node *currentNode = linkedList->head;
    while (currentNode != NULL) {
        printf("%d\t", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

Node* searchNode(LinkedList *linkedList, int data) {
    Node *previous = findPreviousNode(linkedList, data);
    return previous->next;
}
