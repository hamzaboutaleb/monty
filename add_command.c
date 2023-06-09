#include "monty.h"

/**
  * add_command - add
  * @s: pointer to stack
  * @line: line
  */

void add_command(stack_t **s, unsigned int line)
{
	stack_t *temp;
	(void) s;
	(void) line;

	if (!app.tail || app.tail->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", app.line);
		end_app();
		exit(EXIT_FAILURE);
	}

	temp = app.tail;
	app.tail->prev->n += app.tail->n;
	app.tail = app.tail->prev;
	app.tail->next = NULL;
	free(temp);
}
