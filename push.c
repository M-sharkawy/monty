#include "monty.h"

/**
 * push - function for addition of nodes
 *
 * @stack: pointer to the 1st node
 * @ln: lines number
*/


void push(stack_t **stack, unsigned int ln)
{
	int number;
	char **lineArr = g_vars.line_arr;

	if (!lineArr[1])
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		if (*stack)
			free_dlistint(*stack);

		free_cmd(g_vars.line_arr);
		fclose(g_vars.o_bytes);
		exit(EXIT_FAILURE);
	}

	number = atoi(lineArr[1]);
	if (number < 0 ||
	(str_cmp(lineArr[1], "a", str_len("a")) == 0))
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		if (*stack)
			free_dlistint(*stack);

		free_cmd(g_vars.line_arr);
		fclose(g_vars.o_bytes);
		exit(EXIT_FAILURE);
	}

	add_dnodeint(stack, number);
}
