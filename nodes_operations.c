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
	 stack_t *newNode = malloc(sizeof(stack_t));
	if (!newNode)
		return (NULL);

	newNode->n = n;
	newNode->next = *head;
	newNode->prev = NULL;

	if (*head)
	{
		(*head)->prev = newNode;
	}
	*head = newNode;

	return (newNode);
}

/**
 * free_cmd_elements - Function helper to free ele and close prog
 * @cmd_arr: command array
 * @cmd_cpy: command copy
 * @stack: stack linked list
 */

void free_cmd_elements(char **cmd_arr, char *cmd_cpy, stack_t **stack)
{
	perror("Error: malloc failed");
	free_cmd(cmd_arr);
	free(cmd_cpy);
	if (*stack)
		free_dlistint(*stack);

	fclose(g_vars.o_bytes);
}

/**
 * nop - function do nothing.
 *
 * @stack: pointer to top of the stack
 * @line_number: line number
*/

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
