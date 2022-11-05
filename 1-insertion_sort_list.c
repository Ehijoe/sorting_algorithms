#include "sort.h"


/**
 * insertion_sort_list - Sort a doubly linked list with insertion sort
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i;

	if (list == NULL)
		return;
	for (i = *list; i != NULL;)
	{
		listint_t *curr, *prev;

		curr = i;
		i = i->next;
		while (curr->prev != NULL)
		{
			if (curr->n < curr->prev->n)
			{
				/* Swap */
				prev = curr->prev;
				curr->prev = prev->prev;
				prev->next = curr->next;
				curr->next = prev;
				prev->prev = curr;
				if (curr->prev != NULL)
					curr->prev->next = curr;
				if (prev->next != NULL)
					prev->next->prev = prev;
				if (curr->prev == NULL)
					*list = curr;
				print_list(*list);
			}
			else
			{
				break;
			}
		}
	}
}
