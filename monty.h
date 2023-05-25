#ifndef MONTY_H
#define MONTY_H
#define  _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>



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
  * struct app - global app structure
  * @arg: opcode argument
  * @head: pointer to stack
  * @tail: pointer to tail
  * @buffer: app buffer;
  * @file: file descr
  * @line: current line
  */

typedef struct app
{
	char *arg;
	stack_t *head;
	char *buffer;
	FILE *file;
	stack_t *tail;
	unsigned int line;
} app_t;

app_t app;


stack_t *stack_node(int n, stack_t *prev, stack_t *next);
void *malloc_memo(size_t size);
void instruction_err(int line_numbern, char *opcode);
void read_file(void);
void push_command(stack_t **stack, unsigned int line_num);
void pall_command(stack_t **s, unsigned int line);
int is_number(char *s);
void free_list(void);
void pint_command(stack_t **stack, unsigned int line);
void pop_command(stack_t**, unsigned int);
void swap_command(stack_t**, unsigned int);
void add_command(stack_t**, unsigned int);
void nop_command(stack_t**, unsigned int);
void sub_command(stack_t**, unsigned int);
void div_command(stack_t**, unsigned int);
void mul_command(stack_t**, unsigned int);
char *next_token();
void end_app(void);
#endif
