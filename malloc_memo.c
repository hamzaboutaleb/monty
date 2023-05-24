#include "monty.h"

/**
  * malloc_memo - allocate memory
  * @size: size
  * Return: poiter to memory
  */

void *malloc_memo(size_t size)
{
	void *memo;

	memo = malloc(size);
	if (memo == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	return (memo);
}
