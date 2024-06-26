#ifndef __STACK__H__
#define __STACK__H__
#define longueur_max_url 256

typedef enum {
    False,
    True
} Bool;

typedef struct stackElement {
    char url[longueur_max_url];
    struct stackElement *next;
} StackElement;

typedef struct {
    StackElement *top;
} Stack;

void new_stack(Stack *stack);
Bool is_empty_stack(Stack *stack);
void push(Stack *stack, const char *url);
StackElement* pop(Stack *stack);
const char* top(Stack *stack);
void clear_stack(Stack *stack);
void print_stack(Stack stack);
void visit(Stack* history, Stack* forward, const char* url);
void go_back(Stack* history, Stack* forward);
void go_forward(Stack* history, Stack* forward);

#endif
