#include "monty.h"
/**
 * tokenizer - tokenizes a string into words
 * @buffer: is the string to be split
 *
 * Return: a pointer to an array of string or NULL;
 */
char **tokenizer(char *buffer)
{
	char *tok, *delim = " \n";
	char **tokens;
	int i = 0;

	tok = strtok(buffer, delim);
	tokens = malloc(sizeof(char *) * 10);
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (tok != NULL)
	{
		tokens[i] = tok;
		i++;
		tok = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	return (tokens);
}
