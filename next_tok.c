#include "monty.h"


/**
  * next_token - return next token
  * Return: next token
  */
char *next_token(void)
{
	return (strtok(NULL, "\t\n"));
}
