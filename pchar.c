#include "monty.h"

/**
 * pchar - converts number to the ascii character
 * @stack: is the stack on which they number exist
 * @line: is the line numner of which the opcode exists
 */
void pchar(stack_t **stack, unsigned int line)
{
	int num;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;

	if (num >= 0 && num <= 127)
		printf("%c\n", num);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
}
