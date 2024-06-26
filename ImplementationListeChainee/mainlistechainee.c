#include <stdio.h>
#include "listechainee.h"

int main() {
    LinkedList *linkedList = initializeList();
    insertNode(linkedList, 4);
    insertNode(linkedList, 2);

    displayList(linkedList);

    searchNode(linkedList, 4);

    deleteNode(linkedList, 4);
    displayList(linkedList);

    return 0;
}
