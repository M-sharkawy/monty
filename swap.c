#include "monty.h"

/**
 * swap - function to swap two elements of the stack
 *
 * @stack: pointer to the 1st node of linked list
 * @line_number: number line
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int swap_variable;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	temp = (*stack)->next;

	swap_variable = (*stack)->n;
	(*stack)->n = temp->n;
	temp->n = swap_variable;
}
