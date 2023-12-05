#include "main.h"

/**
 * print_list - a function to print all the elements of a
 * list_t list
 * @h: pointer to the head of the list.
 * 
 * Return: returns number of elements
 */

size_t __printlist(_path *h)
{
	unsigned int i;

	for (i = 0; h != NULL; i++)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);
		h = h->next;
	}

	return (i);
}

/**
 * free_list - frees a linked list
 * @head: list_t list to be freed
 */
void __freelist(_path *head)
{
	list_t *temp;

	while (head)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}
