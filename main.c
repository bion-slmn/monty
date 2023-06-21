#define  _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include "monty.h"
#include <string.h>
#include <stddef.h>
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
		free(buffer);
		free_tok(tokens);
	}
	fclose(fd);
	return (0);
}

/**
 * tokenizer - tokenizes a string into words
 * @buffer: is the string to be split
 *
 * Return: a pointer to an array of string or NULL;
 */
char **tokenizer(char *buffer)
{
	char *tok, *dup, *delim = " \n";
	char **tokens;
	int i = 0, numtoken = 0;

	dup = _strdup(buffer);

	tok = strtok(dup, delim);
	while (tok)
	{
		numtoken++;
		tok = strtok(NULL, delim);
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

/**
 * select_func - selects a function to execute
 * @s: is a string passed to the function
 *
 * Return: a pointer corresponding to string
 */
void (*select_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t op[] = {{NULL, NULL}};
	int i = 0;

	while (op[i].opcode != NULL)
	{
		if (!strcmp(s, op[i].opcode))
			return (op[i].f);
		i++;
	}

	return (NULL);
}

/**
 * free_tok - frees memory of the tokens
 * @tokens: double pointer containing strings
 */
void free_tok(char **tokens)
{
	int i = 0;

	while (tokens[i])
	{
		free(tokens[i]);
		tokens[i] = NULL;
		i++;
	}
	free(tokens);
}
/**
 * _strdup - duplicates a string
 * @str: is the string
 *
 * Return: a the duplicated string
 */
char *_strdup(char *str)
{
	char *dup = NULL, *dup_offset;
	int len;

	if (str == NULL)
		return (NULL);

	len = strlen(str);

	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
	{
		return (NULL);
	}

	dup_offset = dup;

	while (*str)
	{
		*dup_offset = *str;
		dup_offset++;
		str++;
	}
	*dup_offset = '\0';

	return (dup);
}
