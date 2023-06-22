#include "monty.h"
/**
 * mod - gets tthe modulus the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can\'t mod, stack too short\n", line_number);
		free_linkedlist(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_linkedlist(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
