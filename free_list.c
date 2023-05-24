#include "monty.h"

/**
  * free_list - free stack
  */
void free_list(void)
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
