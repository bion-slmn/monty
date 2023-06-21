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

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	num = atoi(argument);
	if (!num)
	{
		fprintf(stderr, "L %d:  usage: push integer\n", line_number);
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

/**
 * pall - prints all the values on the stack,
 *	starting from the top of the stack.
 * @stack: is the stack to be added
 * @line_number: is the line number
 *
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!*stack)
		return;

	while (temp->next)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	printf("%d\n", temp->n);
}
/*
void pop(stack_t **stack, unsigned int line_number)
{
}
void add(stack_t **stack, unsigned int line_number)
{
}
void swap(stack_t **stack, unsigned int line_number)
{
}*/
