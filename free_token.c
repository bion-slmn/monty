#include "monty.h"
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
