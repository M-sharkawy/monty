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
	(number == 0 && str_cmp(lineArr[1], "0", str_len("0")) != 0))
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
