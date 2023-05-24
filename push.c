#include "monty.h"
/**
  * push_command - function push to stack
  * @stack: pointer to stack
  * @line_number: current line
  */
void push_command(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	int value;

	value = atoi(app.arg);
	if (app.arg == NULL && is_number(app.arg) == 0 || value == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = stack_node(value, NULL, NULL);

	if (*stack == NULL)
	{
		app.head = node;
		app.tail = node;
		return;
	}

	node->prev = app.tail;
	app.tail->next = node;
	app.tail = node;
}



