#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

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

void instruction_err(int line_number, char * opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

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

int main(int argc, char *argv[])
{
	int file;
	int file_read;
	char *buffer;

	file = init(argc, argv);
	buffer = (char *)malloc_memo(1024);
	file_read = read(file, buffer, 1024);
	printf("%s", buffer);
	
	close(file);
	return (0);
}







