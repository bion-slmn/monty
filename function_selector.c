#include "monty.h"
/**
 * select_func - selects a function to execute
 * @s: is a string passed to the function
 * @line: is the line number of the opcode.
 *
 * Return: a pointer corresponding to string
 */
void (*select_func(char *s, unsigned int line))(stack_t **stack, unsigned int)
{
	instruction_t op[] = {{"push", push},
		{"pall", pall},
		/**
		  *{"pint", pint},
		  *{"pop", pop},
		  *{"swap", swap},
		  * {"add", add},
		 */
		{NULL, NULL}};
	int i = 0;

	while (op[i].opcode != NULL)
	{
		if (!strcmp(s, op[i].opcode))
			return (op[i].f);
		i++;
	}

	fprintf(stderr, "L %d: unknown instruction %s\n", line, s);
	exit(EXIT_FAILURE);
}
