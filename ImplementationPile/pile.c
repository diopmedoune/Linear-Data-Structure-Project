#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pile.h"

Bool is_empty_stack(Pile *pile) {
    return (pile == NULL || pile->premier == NULL) ? True : False;
}

void new_stack(Pile *pile) {
    pile->premier = NULL;
}

int depiler(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int nombreDepile = 0;
    Element *elementDepile = pile->premier;

    if (pile != NULL && pile->premier != NULL)
    {
        nombreDepile = elementDepile->nombre;
        pile->premier = elementDepile->suivant;
        free(elementDepile);
    }

    return nombreDepile;
}

void empiler(Pile *pile, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = nvNombre;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}



void viderPile(Pile *pile)
{
    while (!pile_vide(pile))
    {
        depiler(pile);
    }
}
int pile_vide(Pile *pile)
{
    return (pile == NULL || pile->premier == NULL);
}

void afficherPile(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = pile->premier;

    while (actuel != NULL)
    {
        printf("%d\n", actuel->nombre);
        actuel = actuel->suivant;
    }

    printf("\n");

}

void researchElement(Pile *pile, int elementValeur)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *p = pile->premier;
    while (p != NULL && p->nombre != elementValeur)
    {
        p = p->suivant;
    }

    if (p == NULL)
    {
        printf("L'élément %d ne se trouve pas dans la pile, ajoutons-le.\n", elementValeur);
        empiler(pile, elementValeur);
    }
    else
    {
        printf("L'élément %d se trouve dans la pile.\n", elementValeur);
    }

    afficherPile(pile);
}

