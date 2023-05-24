#include "monty.h"
#include <string.h>
#include <ctype.h>


void (*get_fun(char *opcode))(stack_t **, unsigned int line)
{
	int i;
	instruction_t cmd[] = {
		{"push", push_command},
		{"pall", pall_command},
		{NULL, NULL}
	};

	for (i = 0; cmd[i].opcode != NULL; i++)
	{
		if (strcmp(cmd[i].opcode, opcode) == 0)
		{
			return (cmd[i].f);
		}
	}
	return (NULL);
}

void handle_token(char *token)
{
	void (*fun_ptr)(stack_t **, unsigned int);

	fun_ptr = get_fun(token);
	fun_ptr(&app.head, app.line);
}


void read_file(void)
{
	int rd;
	size_t len = 0;
	char *token;
	char *value;

	while ((rd = getline(&app.buffer, &len, app.file)) > 1)
	{
		token = strtok(app.buffer, " \n\t");
		if (strcmp(token, "push") == 0)
		{
			value = strtok(NULL, " \t");
			app.arg = value;
		}
		handle_token(token);
		app.line++;
		free(app.buffer);
		app.buffer = NULL;
		len = 0;
	}
}
