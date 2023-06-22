#include "monty.h"
/**
* tokenizer - tokenizes a string into words
* @buffer: is the string to be split
*
* Return: a pointer to an array of string or NULL;
*/
char **tokenizer(char *buffer)
{
	char *tok, *dup, *delim = " \n\t";
	char **tokens;
	int i = 0, numtoken = 0;

	if (buffer == NULL)
		return (NULL);
	dup = _strdup(buffer);
	tok = strtok(dup, delim);
	while (tok)
	{
		numtoken++;
		tok = strtok(NULL, delim);
	}
	if (numtoken == 0)
	{
		free(dup);
		return (NULL);
	}
	tokens = malloc(sizeof(char *) * (numtoken + 1));
	if (tokens == NULL)
		return (NULL);

	tok = strtok(buffer, delim);
	while (tok != NULL)
	{
		tokens[i] = _strdup(tok);
		i++;
		tok = strtok(NULL, delim);
	}
	tokens[numtoken] = NULL;
	free(dup);
	return (tokens);
}
