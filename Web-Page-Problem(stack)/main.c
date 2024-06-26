#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "training.h"

int main() {
    Stack history;
    Stack forward;

    new_stack(&history);
    new_stack(&forward);

    visit(&history, &forward, "https://facebook.com");
    visit(&history, &forward, "https://ept.sn");
    visit(&history, &forward, "https://instagram/contact");
    visit(&history, &forward, "https://Structure/about");
    visit(&history, &forward, "https://Algorithmique");

    go_back(&history, &forward); 
    go_back(&history, &forward); 

    go_forward(&history, &forward); 
    go_forward(&history, &forward); 

    printf("\nFinal History Stack:\n");
    print_stack(history);
    printf("\nFinal Forward Stack:\n");
    print_stack(forward);

    clear_stack(&history);
    clear_stack(&forward);

    return 0;
}