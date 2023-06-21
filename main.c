#define  _POSIX_C_SOURCE 200809L
#include "monty.h"
char *argument = NULL;
/**
 * main - is the enterance of program.
 * @argc: is the argument count
 * @argv: is pointer containg al the arguments.
 *
 * Return: 0 on suceess
 */
int main(int argc, char **argv)
{
	size_t len = 0;
	FILE *fd;
	char *buffer = NULL, **tokens;
	stack_t *stack;
	unsigned int line_number;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buffer, &len, fd) != -1)
	{
		line_number++;
		tokens = tokenizer(buffer);
		argument = tokens[1];
		select_func(tokens[0])(&stack, line_number);
		free_tok(tokens);
		/*free(buffer);*/
	}
	fclose(fd);
	return (0);
}
