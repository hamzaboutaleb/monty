#include "monty.h"

/**
  * get_fun - return function for every op code
  * @opcode - opcode name
  * Return: function pointer to specifc opcode
  */
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

/**
  * handle_token - function to handle tokens
  * @token: token
  */
void handle_token(char *token)
{
	void (*fun_ptr)(stack_t **, unsigned int);

	fun_ptr = get_fun(token);
	fun_ptr(&app.head, app.line);
}

/**
  * read_file - read file
  */
void read_file(void)
{
	int rd;
	size_t len = 0;
	char *token;
	char *value;

	while ((rd = getline(&app.buffer, &len, app.file)) != EOF)
	{
		token = strtok(app.buffer, " \n\t");
		if (token == NULL)
		{
			app.line++;
			continue;
		}
		if (strcmp(token, "push") == 0)
		{
			value = strtok(NULL, " \n\t");
			app.arg = value;
			value = strtok(NULL, " \n\t");
			if (value != NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", app.line);
				exit(EXIT_FAILURE);
			}
		}
		handle_token(token);
		app.line++;
		free(app.buffer);
		app.buffer = NULL;
		len = 0;
	}
}
