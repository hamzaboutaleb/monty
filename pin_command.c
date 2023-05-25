#include "monty.h"

/**
  * pint_command - print last elemnt
  * @stack: pointer to stack
  * @line: line
  */
void pint_command(stack_t **stack, unsigned int line)
{
	(void) stack;
	(void) line;

	if (!app.tail)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", app.line);
		end_app();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", app.tail->n);
}
