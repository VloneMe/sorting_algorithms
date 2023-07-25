#include "sort.h"

/**
 * len_list - function to return the length of a linked list
 * @h: pointer to the list
 *
 * Return: length of list
 */
int len_list(listint_t *h)
{
	int len = 0;

	while (h)
	{
		len++;
		h = h->next;
	}
	return (len);
}

/**
 * insertion_sort_list - function to sort linked list
 * with insertion Sort algorithm
 * @list: double pointer to the list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *prev_one = NULL;
	listint_t *prev_two = NULL, *prev_three = NULL, *next_node = NULL;

	if (!list || !(*list) || len_list(*list) < 2)
		return;

	current = *list;
	while (current)
	{
		if (current->prev && current->n < current->prev->n)
		{
			prev_one = current->prev->prev;
			prev_two = current->prev;
			prev_three = current;
			next_node = current->next;
			prev_two->next = next_node;
			if (next_node)
				next_node->prev = prev_two;
			prev_three->next = prev_two;
			prev_three->prev = prev_one;
			if (prev_one)
				prev_one->next = prev_three;
			else
				*list = prev_three;
			prev_two->prev = prev_three;
			current = *list;
			print_list(*list);
			continue;
		}
		else
			current = current->next;
	}
}
