#include "monty.h"

/**
  * instruction_err - print error instruction
  * @line_number: line number of code
  * @opcode: opcode name
  */
void instruction_err(int line_number, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
