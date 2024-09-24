#include "monty.h"

/**
 * pop - function to delete the 1st node
 *
 * @stack: pointer to the 1st node
 * @line_number: line number
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_cmd(g_vars.line_arr);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	*stack = (*stack)->next;
	if (*stack)
	{
		(*stack)->prev = NULL;
		}

	free(ptr);
}
