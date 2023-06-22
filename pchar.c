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
/**
 * rotl -  rotates the stack to the top.
 *	the top element of the stack becomes the last one,
 *	and the second top element of the stack becomes the first one
 *
 * @stack: is the stack on which they number exist
 * @line: is the line numner of which the opcode exists
 */
void rotl(stack_t **stack, unsigned int line)
{
	stack_t *temp, *temp1;
	(void) line;

	if (!*stack || !(*stack)->next)
		return;
	/* diconnecting the top node */
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = NULL;

	/* addding the diconnected node at end*/
	temp1 = *stack;

	while (temp1->next)
		temp1 = temp1->next;

	temp1->next = temp;
	temp->prev = temp1;
}
