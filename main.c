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
	stack_t *head = NULL;
	unsigned int line_number = 0;

	validate_arg(argc);
	fd = fopen(argv[1], "r");
	if (fd == NULL)
		cant_open(argv[1]);
	while (getline(&buffer, &len, fd) != -1)
	{
		line_number++;
		tokens = tokenizer(buffer);
		if (!tokens)
			continue;
		if (tokens[0][0] == '#')
		{
			free_tok(tokens);
			continue;
		}
		argument = tokens[1];
		if (!(select_func(tokens[0], line_number)))
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
					line_number, tokens[0]);
			free(buffer);
			free_tok(tokens);
			free_linkedlist(head);
			fclose(fd);
			exit(EXIT_FAILURE);
		}
		select_func(tokens[0], line_number)(&head, line_number);
		free_tok(tokens);
	}
	fclose(fd);
	free(buffer);
	free_linkedlist(head);
	return (0);
}

/**
 * validate_arg - validate the number of argument
 * @argc: the number of arguments passed
 */
void validate_arg(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
		return;
}
/**
 * cant_open - prints an error message when can open file
 * @str: is the name of the file
 */
void cant_open(char *str)
{
	fprintf(stderr, "Error: Can't open file %s\n", str);
	exit(EXIT_FAILURE);
}
