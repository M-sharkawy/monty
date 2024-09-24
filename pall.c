#include "monty.h"

/**
 * pall - function to print all list values
 *
 * @stack: pointer to the list
 * @line_number: line number
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (*stack == NULL)
	{
		return;
	}

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
