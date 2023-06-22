#include "monty.h"
/**
 * select_func - selects a function to execute
 * @s: is a string passed to the function
 * @line: is the lin number.
 *
 * Return: a pointer corresponding to string
 */
void (*select_func(char *s, unsigned int line))(stack_t **stack, unsigned int)
{
	instruction_t op[] = {{"push", push},
		{"add", add},
		{"nop", nop},
		{"pall", pall},
		/**
		  *{"pint", pint},
		  *{"pop", pop},
		  *{"swap", swap},
		 */
		{NULL, NULL}};
	int i = 0;

	while (op[i].opcode != NULL)
	{
		if (!strcmp(s, op[i].opcode))
			return (op[i].f);
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, s);
	exit(EXIT_FAILURE);
}
