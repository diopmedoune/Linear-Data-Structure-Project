typedef struct Contact {
    char lastName[20];
    char firstName[20];
    char phone[15];
} Contact;

typedef struct Node {
    Contact data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
} LinkedList;

Contact createContact(char lastName[], char firstName[], char phone[]);

void displayContact(Contact c);

void modifyPhone(Contact *c, char newPhone[]);

LinkedList* initializeList();

void insertNode(LinkedList *linkedList, Contact c);

int compareContact(Contact c1, Contact c2);

void deleteNode(LinkedList *linkedList, Contact c);

void displayList(LinkedList *linkedList);

Node* findPreviousNode(LinkedList *linkedList, Contact c);

void searchByLastName(LinkedList *linkedList, char lastName[]);

void searchByFirstName(LinkedList *linkedList, char firstName[]);

void searchByFullName(LinkedList *linkedList, char lastName[], char firstName[]);
