#include "linked_list.h"

/** add_at_index
 * 
 * Creates and adds a node at the specified index in the provided linked list.
 * 
 * @param head Pointer to the list which will be added to
 * @param val Val attribute of the node to be added
 * @param index Index in the linked list where the node will be added (0 indexed)
 * @return FAILURE if list is NULL, if malloc fails, or if index is invalid
 * SUCCESS otherwise.
*/
int add_at_index(LinkedList *list, int val, int index) {

    if (!list || index < 0) {
        return FAILURE
    }

    if (index == 0) {
        Node *new_node = malloc(sizeof(Node));

        if (!new_node) {
            return FAILURE;
        }

        new_node->val = val;
        new_node->next = list->head;
        list->head = new_node;

        return SUCCESS;
    }
    Node *current = list->head;

    // Edge Case for a linkedlist - adding when index = 0 -> index - 1 -> 0 - 1 is an issue OutofBoundsException

    for (int n = 0; n < index; ++n) {
        if (currenr == NULL) {
            // Checking whether the first node is equal to NULL
            return FAILURE;
        }

        // Iterate to the next node in the linked list
        current = current->next;
    }

    if (current == NULL) {
        return FAILURE;
    }

    // Now time to add the node to the linked list
    // We will implement malloc

    // Allocate space for one node
    Node *new_node = malloc(sizeof(Node));

    if (!new_node) {
        return FAILURE;
    }

    new_node->val = val;
    new_node->next = current->next;

    // We haven't checked if current->next is NULL
    // However that's okay since the last element in the linked list points to NULL
}
