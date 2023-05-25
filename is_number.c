#include "monty.h"

/**
  * is_number - check if char is number
  * @s: charcetr to check
  * Return: 0 if not number 1othrwise
  */
int is_number(char *s)
{

	while (*s != '\0')
	{
		if (!isdigit(*s))
			return (0);
		s++;
	}

	return (1);
}
