#include <stdio.h>
#include "testliste.h"

int main() {

    Contact c1 = createContact("Ndiaye", "Mamadou", "779993322");
    Contact c2 = createContact("Thiaw", "Nogaye", "776665532");

    LinkedList *linkedList = initializeList();

    //insertion du premier contact
    insertNode(linkedList, c1);

    //insertion du second contact
    insertNode(linkedList, c2);

    //Affichage de la liste chainee
    printf("-------------Affichage de liste chainee\n--------------");
    displayList(linkedList);

    //Suppression du contact c1
    deleteNode(linkedList, c1);

    //Affichage de la liste chainee
    printf("-------------Affichage de liste chainee--------------\n");
    displayList(linkedList);

    //Recherche des contacts avec le nom "Ndiaye"
    printf("---------------Recherche des contacts avec le nom 'Ndiaye'---------------\n");
    searchByLastName(linkedList, "Ndiaye");

    //Recherche des contacts avec le prenom 'Nogaye'
    printf("-----------Recherche des contacts avec le prenom 'Nogaye'--------------\n");
    searchByFirstName(linkedList, "Nogaye");

    //Recherche des contacts avec le prenom 'Nogaye' et le nom 'Ndiaye'
    printf("-----------------Recherche des contacts avec le prenom 'Nogaye' et le nom 'Ndiaye'-----------------\n");
    searchByFullName(linkedList, "Ndiaye", "Nogaye");

    return 0;
}
