#include "monty.h"

/**
 * sub - subtract the 1st two elements and store in the top
 *
 * @stack: pointer to the top of stack
 * @line_number: line number
*/

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int node1, node2, subt;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (temp)->next;
	node1 = temp->n;
	node2 = (*stack)->n;
	subt = node2 - node1;
	(*stack)->n = subt;

	free(temp);
}
