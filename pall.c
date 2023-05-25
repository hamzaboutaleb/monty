#include "monty.h"

/**
  * pall_command - show all stack
  * @s: pointer to stack
  * @line: current line
  */
void pall_command(stack_t **s, unsigned int line)
{
	stack_t *el;
	(void) line;
	(void) s;

	if (app.tail == NULL)
		return;
	el = app.tail;
	while (el != NULL)
	{
		printf("%d\n", el->n);
		el = el->prev;
	}
}
