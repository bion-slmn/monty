#include "monty.h"
/**
 * pall - prints all the values on the stack,
 *    starting from the top of the stack.
 * @stack: is the stack to be added
 * @line_number: is the line number
 *
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
		return;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
