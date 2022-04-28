#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a new node at the end of a listint_t list
 *
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 *
 *  Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *temp = *head;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	new->n = number;

	if (temp == NULL || temp->n > number)
	{
		new->next = temp;
		*head = new;
		return (new);
	}

	while (temp->next != NULL && temp->next->n < number)
	{
		temp = temp->next;
	}

	new->next = temp->next;
	temp->next = new;

	return (new);
}
