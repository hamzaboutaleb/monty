#include "monty.h"

/**
  * sub_command - subtract two top element
  * @s: pointer to stack
  * @ln: number line
  */
void sub_command(stack_t **s, unsigned int ln)
{
	stack_t *curr, *prev;
	(void) s;

	if (!app.tail || !app.tail->prev)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		end_app();
		exit(EXIT_FAILURE);
	}

	curr = app.tail;
	prev = app.tail->prev;

	prev->n -= curr->n;
	prev->next = NULL;
	free(curr);
	app.tail = prev;
}
