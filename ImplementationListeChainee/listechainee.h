typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
} LinkedList;

LinkedList* initializeList();

void insertNode(LinkedList *linkedList, int data);

void deleteNode(LinkedList *linkedList, int data);

void displayList(LinkedList *linkedList);

Node* findPreviousNode(LinkedList *linkedList, int data);

Node* searchNode(LinkedList *linkedList, int data);
