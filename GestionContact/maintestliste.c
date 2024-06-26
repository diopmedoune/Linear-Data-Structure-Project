#include <stdio.h>
#include "testliste.h"

int main() {

    Contact c1 = createContact("Ndiaye", "Maimouna", "779993322");

    LinkedList *linkedList = initializeList();
    insertNode(linkedList, c1);
    Contact c2 = createContact("Thiaw", "Nogaye", "776665532");
    insertNode(linkedList, c2);
    displayList(linkedList);

    deleteNode(linkedList, c1);
    displayList(linkedList);

    searchByLastName(linkedList, "Ndiaye");

    searchByFirstName(linkedList, "Nogaye");

    searchByFullName(linkedList, "Ndiaye", "Nogaye");

    return 0;
}
