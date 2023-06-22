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
	stack_t *stack = NULL;
	unsigned int line = 0;


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
		line++;
		tokens = tokenizer(buffer);
		if (!tokens)
			continue;
		argument = tokens[1];
		select_func(tokens[0], line)(&stack, line);
		free_tok(tokens);
	}
	/*free_tok(tokens);*/
	free_stack(stack);
	free(buffer);
	fclose(fd);
	return (0);
}

/**
 * free_dlistint - free dlistint list
 * @head: is the begining of list
 *
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while(head)
	{
	temp = head;
        head = head->next;
        free(temp);
	}
	head = NULL;
}
