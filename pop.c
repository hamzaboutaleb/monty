#include "monty.h"

/**
  * pop_command - delete last element
  * @stack: pointer to stack
  * @line: line number
  */
void pop_command(stack_t **stack, unsigned int line)
{
	stack_t *ptr;
	(void) line;
	(void) stack;

	if (!app.tail)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", app.line);
		end_app();
		exit(EXIT_FAILURE);
	}

	ptr = app.tail;
	if (ptr->prev)
	{
		app.tail = ptr->prev;
		app.tail->next = NULL;
	}
	else
		app.tail = NULL, app.head = NULL;
	free(ptr);
}
