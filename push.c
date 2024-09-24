#include "monty.h"



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
   if (number == 0 && strcmp(lineArr[1], "0") != 0)
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
