#include "monty.h"


void free_list()
{
	stack_t *curr, *next;

	curr = app.head;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}
