#include "monty.h"

/**
  * mul_command - multiple top 2 element
  * @s: stack
  * @ln: number ln
  */
void mul_command(stack_t **s, unsigned int ln)
{
	stack_t *curr, *prev;
	(void) s;

	if (!app.tail || !app.tail->prev)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
		end_app();
		exit(EXIT_FAILURE);
	}

	curr = app.tail;
	prev = app.tail->prev;

	prev->n *= curr->n;
	prev->next = NULL;
	free(curr);
	app.tail = prev;
}
