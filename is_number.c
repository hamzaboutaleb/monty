#include "monty.h"


int is_number(char *s)
{

	while (*s != '\0')
	{
		if (isdigit(*s) == 0)
			return (0);
		s++;
	}

	return (1);
}
