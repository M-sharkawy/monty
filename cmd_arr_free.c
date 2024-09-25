#include "monty.h"

/**
 * free_cmd_elements - Function helper to free ele and close prog
 * @cmd_arr: command array
 * @cmd_cpy: command copy
 * @stack: stack linked list
 */

void free_cmd_elements(char **cmd_arr, char *cmd_cpy, stack_t **stack)
{
	perror("Error: malloc failed");
	free_cmd(cmd_arr);
	free(cmd_cpy);
	if (*stack)
		free_dlistint(*stack);

	fclose(g_vars.o_bytes);
}
