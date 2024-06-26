#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "web_page.h"


void new_stack(Stack *stack) {
    stack->top = NULL;
}

Bool is_empty_stack(Stack *stack) {
    return (stack->top == NULL) ? True : False;
}

void push(Stack *stack, const char *url) {
    StackElement *newElement = (StackElement *)malloc(sizeof(StackElement));
    if (newElement != NULL) {
        strncpy(newElement->url, url, longueur_max_url - 1);
        newElement->url[longueur_max_url - 1] = '\0';
        newElement->next = stack->top;
        stack->top = newElement;
    } else {
        fprintf(stderr, "Erreur: allocation mémoire échouée\n");
    }
}

StackElement* pop(Stack *stack) {
    if (is_empty_stack(stack)) {
        return NULL;
    }
    StackElement *element = stack->top;
    stack->top = stack->top->next;
    return element;
}

const char* top(Stack *stack) {
    if (is_empty_stack(stack)) {
        return NULL;
    }
    return stack->top->url;
}

void clear_stack(Stack *stack) {
    while (!is_empty_stack(stack)) {
        StackElement *element = pop(stack);
        if (element != NULL) {
            free(element);
        }
    }
}

void print_stack(Stack stack) {
    if (is_empty_stack(&stack)) {
        printf("Rien a afficher, la Pile est vide\n");
        return;
    }
    StackElement *current = stack.top;
    while (current != NULL) {
        printf("[%s]\n", current->url);
        current = current->next;
    }
}

void visit(Stack* history, Stack* forward, const char* url) {
    push(history, url);
    clear_stack(forward);
    printf("Tu visites la page: %s\n", url);
}

void go_back(Stack* history, Stack* forward) {
    if (is_empty_stack(history)) {
        printf("Aucune page dans l'historique\n");
        return;
    }
    StackElement *element = pop(history);
    if (element != NULL) {
        push(forward, element->url);
        free(element);
    }
    if (!is_empty_stack(history)) {
        printf("Retournons a la page : %s\n", top(history));
    } else {
        printf("No more history\n");
    }
}

void go_forward(Stack* history, Stack* forward) {
    if (is_empty_stack(forward)) {
        printf("Pas de pages disponibles pour aller en avant\n");
        return;
    }
    StackElement *element = pop(forward);
    if (element != NULL) {
        push(history, element->url);
        printf("Allons en avant vers la page : %s\n", element->url);
        free(element);
    }
}