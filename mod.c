#include "monty.h"

/**
 * _mod - modules the 1st two elements and store in the top
 *
 * @stack: pointer to the top of stack
 * @line_number: line number
*/

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int node1, node2, result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (temp)->next;
	node1 = temp->n;
	node2 = (*stack)->n;

	if (node1 == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		result = node2 % node1;
		(*stack)->n = result;
	}

	free(temp);
}
