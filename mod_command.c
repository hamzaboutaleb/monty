#include "monty.h"

/**
  * mod_command - modulo top 2 element
  * @s: stack
  * @ln: line number
  */
void mod_command(stack_t **s, unsigned int ln)
{
	stack_t *curr, *prev;

	(void) s;

	if (!app.tail || !app.tail->prev)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
		end_app();
		exit(EXIT_FAILURE);
	}

	if (app.tail->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		end_app();
		exit(EXIT_FAILURE);
	}

	curr = app.tail;
	prev = app.tail->prev;

	prev->n %= curr->n;
	prev->next = NULL;
	free(curr);
	app.tail = prev;
}
