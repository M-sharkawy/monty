#include "monty.h"

/**
 * pint - function to print the 1st value in the list
 *
 * @stack: pointer to the list
 * @line_number: number line
*/

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(g_vars.o_bytes);
		free_cmd(g_vars.line_arr);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
