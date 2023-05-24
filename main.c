#include "monty.h"

app_t app;

void init_app()
{

}


/**
  * init - init program and open file
  * @argc: arg count
  * @argv: arg list
  * Return: file
  */
int init(int argc, char *argv[])
{
	int file;
	char *file_name;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_name = argv[1];

	file = open(file_name, O_RDONLY);

	if (file == -1)
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
	stack_t *stack;

	int file;
	int file_read;
	char *buffer;

	file = init(argc, argv);

	stack = (stack_t *)malloc_memo(sizeof(stack_t));
	buffer = (char *)malloc_memo(1024);

	file_read = read(file, buffer, 1024);
	printf("%s", buffer);

	close(file);
	return (0);
}







