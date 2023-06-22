#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
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
/**
 * pstr - prints the string starting at the top of the stack
 * @stack: is the stack on which they number exist
 * @line: is the line numner of which the opcode exists
 */
void pstr(stack_t **stack, unsigned int line)
{
	int num;
	stack_t *temp = *stack;
	(void)line;

	if (!*stack)
		printf("\n");

	while (temp)
	{
		num = temp->n;
		if (num > 0 && num <= 127)
		{
			printf("%c", num);
			temp = temp->next;
		}
		else
			break;
	}
	printf("\n");
}
