#include "monty.h"

app_t app;

/**
  * init_app - intialize app
  * @file: file to read
  */
void init_app(FILE *file)
{
	app.arg = NULL;
	app.buffer = NULL;
	app.head = NULL;
	app.tail = NULL;
	app.file = file;
	app.line = 1;
}
/**
  * end_app - free memory
  */
void end_app(void)
{
	free_list();
	free(app.buffer);
	fclose(app.file);
}

/**
  * init - init program and open file
  * @argc: arg count
  * @argv: arg list
  * Return: file
  */
FILE *init(int argc, char *argv[])
{
	FILE *file;
	char *file_name;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_name = argv[1];

	file = fopen(file_name, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	return (file);
}

/**
  * main - entry point to program
  * @argc: arg count
  * @argv: arg list
  * Return: 0
  */

int main(int argc, char *argv[])
{

	FILE *file;

	file = init(argc, argv);
	init_app(file);

	read_file();

	end_app();
	return (0);
}







