#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of a stack_t list
 * @head: pointer points to pointer which points to head
 * @n: integer valuje to be added
 *
 * Return: (*head) which is the head node
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *temp = *head, *newNode;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;
	if (!(*head))
	{
		newNode->prev = (*head);
		(*head) = newNode;
	} else
	{
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}

	return (newNode);
}
