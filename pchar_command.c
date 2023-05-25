#include "monty.h"

/**
  * pchar_command - print last char
  * @s: stack
  * @ln: line number
  */
void pchar_command(stack_t **s, unsigned int ln)
{
	int last_value;
	(void) s;

	if (!app.tail)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
		end_app();
		exit(EXIT_FAILURE);
	}

	last_value = app.tail->n;

	if (last_value > 127 || last_value < 32)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
		end_app();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", last_value);

}
