#include "monty.h"

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

	num = atoi(argument);
	if (!num)
	{
		fprintf(stderr, "L %d :  usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}

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
