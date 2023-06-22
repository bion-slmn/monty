#include "monty.h"
/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_linkedlist(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;

	sum = temp->n + temp->next->n;
	(*stack)->n = sum;
	free(temp);
	(*stack)->prev = NULL;
}
