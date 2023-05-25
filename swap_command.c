#include "monty.h"

/**
  * swap_command - swap top 2 number
  * @s: pointer to stack
  * @line: line num
  */
void swap_command(stack_t **s, unsigned int line)
{
	int temp;
	(void) s;
	(void) line;

	if (!app.tail || app.tail->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", app.line);
		end_app();
		exit(EXIT_FAILURE);
	}

	temp = app.tail->n;
	app.tail->n = (app.tail->prev)->n;
	app.tail->prev->n = temp;
}
