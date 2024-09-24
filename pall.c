#include "monty.h"



void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (*stack)
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		while (tmp)
		{
			printf("%d\n", tmp->n);	
			tmp = tmp->prev;
		}
		
	}
}
