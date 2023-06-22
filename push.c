#include "monty.h"
#include <ctype.h>

/**
 * push - it add a node to the stack fromthe top
 * @stack: is the stack to be added
 * @line_number: is the line number
 *
 */
void push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	int num;

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (argument == NULL && (is_integer(argument) == 0))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(argument);
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!stack)
		return;

	new->n = num;
	new->prev = NULL;
	new->next = NULL;

	if (*stack == NULL)
	{
		*stack = new;
	}
	else
	{
		new->next  = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}
