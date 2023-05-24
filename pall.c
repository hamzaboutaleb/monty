#include "monty.h"


void pall_command(stack_t **s, unsigned int line)
{
	stack_t *el;


	if (*s == NULL)
		return;
	el = app.tail;
	while (el != NULL)
	{
		printf("%d\n", el->n);
		el = el->prev;
	}
}
