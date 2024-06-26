#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testliste.h"

Contact createContact(char lastName[], char firstName[], char phone[]) {
    Contact c;
    strcpy(c.lastName, lastName);
    strcpy(c.firstName, firstName);
    strcpy(c.phone, phone);
    return c;
}

void displayContact(Contact c) {
    printf("le nom: %s\n", c.lastName);
    printf("le prenom: %s\n", c.firstName);
    printf("le telephone: %s\n", c.phone);
}

void modifyPhone(Contact *c, char newPhone[]) {
    strcpy(c->phone, newPhone);
}

LinkedList* initializeList() {
    LinkedList *linkedList = malloc(sizeof(*linkedList));
    if (linkedList == NULL) {
        exit(0);
    }
    linkedList->head = NULL;
    return linkedList;
}

void insertNode(LinkedList *linkedList, Contact c) {
    Node *newNode = malloc(sizeof(*newNode));
    if (linkedList == NULL || newNode == NULL) {
        exit(0);
    }
    newNode->data = c;
    newNode->next = linkedList->head;
    linkedList->head = newNode;
}

void displayList(LinkedList *linkedList) {
    if (linkedList == NULL) {
        exit(0);
    }

    Node *currentNode = linkedList->head;
    while (currentNode != NULL) {
        displayContact(currentNode->data);
        currentNode = currentNode->next;
    }

    printf("NULL\n");
}

int compareContact(Contact c1, Contact c2) {
    if (strcmp(c1.lastName, c2.lastName) != 0) {
        return 0;
    }
    if (strcmp(c1.firstName, c2.firstName) != 0) {
        return 0;
    }
    if (strcmp(c1.phone, c2.phone) != 0) {
        return 0;
    }
    return 1;
}


void deleteNode(LinkedList *linkedList, Contact c) {
    if (linkedList == NULL) {
        exit(0);
    }

    if (linkedList->head != NULL && compareContact(linkedList->head->data, c)) {
        Node *nodeToDelete = linkedList->head;
        linkedList->head = linkedList->head->next;
        free(nodeToDelete);
    } else {
        Node *previous = findPreviousNode(linkedList, c);
        Node *temp1 = previous;
        Node *temp2 = previous->next;
        temp1->next = temp2->next;
        free(temp2);
    }
}

void searchByLastName(LinkedList *linkedList, char lastName[]) {
    int found = 0;
    if (linkedList == NULL) {
        exit(0);
    }

    Node *current = linkedList->head;
    while (current != NULL) {
        if (strcmp(current->data.lastName, lastName) == 0) {
            displayContact(current->data);
            found++;
        }
        current = current->next;
    }
    if (found == 0) {
        printf("Contact avec ce nom introuvable\n");
    }
}

void searchByFirstName(LinkedList *linkedList, char firstName[]) {
    int found = 0;
    if (linkedList == NULL) {
        exit(0);
    }

    Node *current = linkedList->head;
    while (current != NULL) {
        if (strcmp(current->data.firstName, firstName) == 0) {
            displayContact(current->data);
            found++;
        }
        current = current->next;
    }
    if (found == 0) {
        printf("Contact avec ce prenom introuvable\n");
    }
}

void searchByFullName(LinkedList *linkedList, char lastName[], char firstName[]) {
    int found = 0;
    if (linkedList == NULL) {
        exit(0);
    }

    Node *current = linkedList->head;
    while (current != NULL) {
        if (strcmp(current->data.lastName, lastName) == 0 && strcmp(current->data.firstName, firstName) == 0) {
            displayContact(current->data);
            found++;
        }
        current = current->next;
    }
    if (found == 0) {
        printf("Contact avec ce nom et ce prenom introuvable\n");
    }
}
