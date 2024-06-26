#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element Element;

struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Pile Pile;

struct Pile
{
    Element *premier;
};

typedef enum {
    False,
    True
} Bool;



Bool is_empty_stack(Pile *pile);
void new_stack(Pile *pile);
int depiler(Pile *pile);
void empiler(Pile *pile, int nvNombre);
void viderPile(Pile *pile);
int pile_vide(Pile *pile);
void afficherPile(Pile *pile);
void researchElement(Pile *pile, int elementValeur);






