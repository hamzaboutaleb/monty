#include "monty.h"

/**
  * div_command - div top 2 element on stack
  * @s: pointer to stack
  * @ln: line number
  */
void div_command(stack_t **s, unsigned int ln)
{
	stack_t *curr, *prev;

	(void) s;

	if (!app.tail || !app.tail->prev)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln);
		end_app();
		exit(EXIT_FAILURE);
	}
	curr = app.tail;
	prev = app.tail->prev;

	if (curr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		end_app();
		exit(EXIT_FAILURE);
	}

	prev->n /= curr->n;
	prev->next = NULL;
	free(curr);
	app.tail = prev;
}
