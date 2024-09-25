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

/**
 * _div - division the 1st two elements and store in the top
 *
 * @stack: pointer to the top of stack
 * @line_number: line number
*/

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int node1, node2, result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
		result = node2 / node1;
		(*stack)->n = result;
	}

	free(temp);
}

/**
 * mul - multiple the 1st two elements and store in the top
 *
 * @stack: pointer to the top of stack
 * @line_number: line number
*/

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int node1, node2, mult;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (temp)->next;
	node1 = temp->n;
	node2 = (*stack)->n;
	mult = node2 * node1;
	(*stack)->n = mult;

	free(temp);
}

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
