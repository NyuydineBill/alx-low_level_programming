#include "lists.h"

/**
 * free_list - frees a list
 * @head: head of the linked list.
 *Bill
 * This function frees a linked list.
 */
void free_list(list_t *head)
{
	list_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current->str);
		free(current);
	}
}
