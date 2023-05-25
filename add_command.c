#include "monty.h"

/**
  * add_command - add
  * @s: pointer to stack
  * @line: line
  */

void add_command(ctack_t **s, unsigned int line)
{
	stack_t *temp;

	if (app.tail->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", app.line);
		end_app();
		exit(EXIT_FAILURE);
	}

	temp = app.tail;
	app.tail->prev->n += app.tail->n;
	app.tail = app.tail->prev;
	free(temp);
}
