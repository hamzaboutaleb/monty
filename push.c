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

	app.arg = strtok(next_token(), " \t\n");
	if (app.arg == NULL || next_token() != NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", app.line);
		end_app();
		exit(EXIT_FAILURE);
	}
	value = atoi(app.arg);
	if (app.arg == NULL && is_number(app.arg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		end_app();
		exit(EXIT_FAILURE);
	}
	node = stack_node(value, NULL, NULL);
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		end_app();
		exit(EXIT_FAILURE);
	}
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



