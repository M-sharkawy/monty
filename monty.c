#include "monty.h"

global_v g_vars;

/**
 * main - take argument from command line
 *
 * @argc: count of args
 * @argv: arguments pointer
 *
 * Return: 0 always sucess
*/


int main(int argc, char **argv)
{
	char buff[1024];
	stack_t *stack = NULL;
	int status;

	(void)status;
	if (argc != 2)
		handle_usage();

	open_file(argv[1]);

	while (fgets(buff, 1024, g_vars.o_bytes))
	{
		g_vars.ln++;
		g_vars.line_arr = cmd_arr(buff, &stack);
		if (!g_vars.line_arr)
			continue;

		status = lineInput(g_vars.line_arr, &stack, g_vars.ln);
		if (status < 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", g_vars.ln,
			g_vars.line_arr[0]);
			free_dlistint(stack);
			free_cmd(g_vars.line_arr);
			fclose(g_vars.o_bytes);
			exit(EXIT_FAILURE);
		}
		free_cmd(g_vars.line_arr);
	}

	if (stack)
		free_dlistint(stack);

	fclose(g_vars.o_bytes);
	return (0);
}

/**
 * open_file - open file
 *
 * @filename: file to be opened
*/

void open_file(const char *filename)
{
	g_vars.o_bytes = fopen(filename, "r");
	if (!g_vars.o_bytes)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_usage - error handling
*/

void handle_usage(void)
{
	write(STDERR_FILENO, "USAGE: monty file\n", 19);
	exit(EXIT_FAILURE);
}
