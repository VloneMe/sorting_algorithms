#include "sort.h"

void swap_node_next(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_prev(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_next - Function to swap a node in a listint_t doubly-linked list
 * @list: A pointer to the head of a doubly-linked list of integers
 * @tail: A pointer to the tail of the doubly-linked list
 * @shaker: A pointer to the current swapping node of the cocktail
 */
void swap_node_next(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*shaker)->prev;
	(*shaker)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = temp;
	temp->next = *shaker;
	*shaker = temp;
}

/**
 * swap_node_orev - function to swap a node in a listint_t doubly-linked list
 * @list: A pointer to the head of a doubly-linked list
 * @tail: A pointer to the tail of the doubly-linked list
 * @shaker: A pointer to the current swapping node of the cocktail shaker algorithm.
 */
void swap_node_prev(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*shaker)->next;
	(*shaker)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = temp;
	temp->prev = *shaker;
	*shaker = temp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_list = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_list == false)
	{
		shaken_list = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_next(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_list = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_prev(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_list = false;
			}
		}
	}
}
