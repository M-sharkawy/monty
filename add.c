#include "monty.h"

/**
 * add - function to add the first two elements together
 *
 * @stack: pointer to the linked list
 * @line_number: line number
*/

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int node1, node2, sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (temp)->next;
	node1 = temp->n;
	node2 = (*stack)->n;
	sum = node1 + node2;
	(*stack)->n = sum;

	free(temp);
}
