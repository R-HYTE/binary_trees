#include "binary_trees.h"

/**
 * free_linked_list - Free the memory occupied by the linked list nodes.
 * @head: The pointer to the head of the linked list.
 */
void free_linked_list(link_t *head)
{
        link_t *current, *next;

        current = head;
        while (current)
        {
                next = current->next;
                free(current);
                current = next;
        }
}


