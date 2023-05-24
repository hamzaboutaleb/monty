#include "monty.h"

/**
  * pin_command - print last elemnt
  * @stack: pointer to stack
  @line: line
  */
void pin_command(stack_t **stack, unsigned int line)
{
	(void) stack;
	(void) line;

	if (next_token() != NULL || app.head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", app.line);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", app.tail->n);
}
