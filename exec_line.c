#include "monty.h"

/**
 * cmd_len - Function to get the length of the whole line
 * @line: which is string of the command
 *
 * Return: (i) whcih ios the length
 */

int cmd_len(char *line)
{
	char *token, *lineCpy;
	int i = 0;

	lineCpy = str_dup(line);
	if (!lineCpy)
		return (0);

	token = strtok(line, " \t");
	while (token)
	{
		i++;
		token = strtok(NULL, " \t");
	}
	free(lineCpy);
	return (i);
}

/**
 * cmd_arr - Function to return array of the line
 * @cmd: line which is command to exec
 * @stack: stack linked list
 *
 * Return: array
 * otherwise - NULL
 */

char **cmd_arr(const char *cmd, stack_t **stack)
{
	char *token, **cmdArr, *cmdCpy;
	int length, i = 0, tokLen;

	cmdCpy = str_dup(cmd);
	length = str_len(cmdCpy);
	if (length == 0)
	{
		free(cmdCpy);
		return (NULL);
	}
	cmdArr = malloc(sizeof(char *) * (length + 1));
	if (!cmdArr)
	{
		perror("Error: malloc failed");
		if (*stack)
			free_dlistint(*stack);
		fclose(g_vars.o_bytes);
		return (NULL);
	}
	token = strtok(cmdCpy, " \t\n");

	while (token)
	{
		tokLen = str_len(token) + 1;
		cmdArr[i] = malloc(sizeof(char) * (tokLen));
		if (!cmdArr[i])
		{
			perror("Error: malloc failed");
			free_cmd(cmdArr);
			free(cmdCpy);
			if (*stack)
				free_dlistint(*stack);

			fclose(g_vars.o_bytes);
			return (NULL);
		}
		strcpy(cmdArr[i], token);
		i++;
		token = strtok(NULL, " \t");
	}

	cmdArr[i] = NULL;
	free(cmdCpy);
	return (cmdArr);
}

/**
 * free_cmd - Function to free command array
 * @cmd: command array
 */

void free_cmd(char **cmd)
{
	int i = 0;

	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

/**
 * free_dlistint - function that frees a stack_t list.
 * @head: pinter to the head node
 */

void free_dlistint(stack_t *head)
{
	stack_t *temp = head;

	while (temp)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
}

/**
 * lineInput - 
 */
int lineInput(char **line_arr, stack_t **stack, unsigned int ln)
{
	int i = 0;

	instruction_t operations[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	while (operations[i].opcode)
	{
		if (str_cmp(line_arr[0], operations[i].opcode, str_len(line_arr[0])) == 0)
		{
			operations[i].f(stack, ln);
			return (0);
		}
		i++;
	}

	return (-1);
}
