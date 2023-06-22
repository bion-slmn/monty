#include "monty.h"
#include <ctype.h>

/**
 * push - it add a node to the stack fromthe top
 * @stack: is the stack to be added
 * @line_number: is the line number
 *
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	int num;

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (argument == NULL && (isNumber(argument) == 0))
	{
		fprintf(stderr, "L %d:  usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(argument);

	new->n = num;
	new->prev = NULL;
	new->next = NULL;

	if (!stack)
		return;
	if (*stack == NULL)
	{
		*stack = new;
	}
	else
	{
		new->next  = *stack;
		*stack = new;
	}
}
/**
 * isNumber - checks if the string consists of numbers
 * @s: is the string
 *
 * Return: 1 on sucess and 0 on failure
 */
int isNumber(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (isdigit(s[i]))
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}
