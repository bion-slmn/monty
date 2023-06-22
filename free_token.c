#include "monty.h"
/**
 * free_tok - frees memory of the tokens
 * @tokens: double pointer containing strings
 */
void free_tok(char **tokens)
{
	if (tokens == NULL)
		return;
	/*while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}*/
	free(tokens);
}
