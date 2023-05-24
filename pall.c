#include "monty.h"

/**
  * pall_command - show all stack
  * @stack: pointer to stack
  * @line: current line
  */
void pall_command(stack_t **s, unsigned int line)
{
	stack_t *el;
	(void) line;

	if (*s == NULL)
		return;
	el = app.tail;
	while (el != NULL)
	{
		printf("%d\n", el->n);
		el = el->prev;
	}
}
