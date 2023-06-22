#include "monty.h"
#include <ctype.h>
/**
  * is_integer - checks if a number is an int or not
  * @input: input of function
  * Return: Returns a 0 (false) or a 1 (true)
  */
int is_integer(const char *input)
{
	if (input == NULL)
		return (0);
	if (*input == '\0')
		return (0);
	if (*input == '+' || *input == '-')
		input++;

	while (*input != '\0')
	{
		if (!isdigit(*input))
			return (0);
		input++;
	}
	return (1);
}
