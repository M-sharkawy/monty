#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_v - Struct to hold all prog variables
 * @o_bytes: open file bytes
 * @ln: number of lines
 * @line_arr: line array
 */

typedef struct global_v
{
	FILE *o_bytes;
	unsigned int ln;
	char **line_arr;
} global_v;

extern global_v g_vars;

int str_len(const char *str);
int str_cmp(const char *str_one, const char *str_two, int bytes);
char *str_dup(const char *str);
char **cmd_arr(const char *cmd, stack_t **stack);
void free_cmd(char **cmd);
int lineInput(char **line_arr, stack_t **stack, unsigned int ln);
int cmd_len(char *line);
void free_cmd_elements(char **cmd_arr, char *cmd_cpy, stack_t **stack);
stack_t *add_dnodeint(stack_t **head, const int n);
void handle_usage(void);
void open_file(const char *filename);
void free_dlistint(stack_t *head);
void push(stack_t **stack, unsigned int ln);
void pall(stack_t **stack, unsigned int ln);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

#endif
