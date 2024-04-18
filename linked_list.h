#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

#define UNUSED(x) void(x)
typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct LinkedList {
    struct Node *head;
} LinkedList;


// LinkedList Methods - Adding

int add_to_front(LinkedList *list, int val);

int add_at_index(LinkedList *list, int val, int index);

int add_to_end(LinkedList *list, int val);


// LinkedList Methods - Removing

int remove_from_front(LinkedList *list);

int remove_from_back(LinkedList *list);

// LinkedList Methods - Retrieving
int get_from_front(LinkedList *list);



