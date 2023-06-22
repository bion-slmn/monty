#include "monty.h"
/**
 * select_func - selects a function to execute
 * @s: is a string passed to the function
 * @line: is the line number of the opcode.
 *
 * Return: a pointer corresponding to string
 */
void (*select_func(char *s))(stack_t **stack, unsigned int)
{
	instruction_t op[] = {{"push", push},
		{"pall", pall},
		/**
		  *{"pint", pint},
		  *{"pop", pop},
		  *{"swap", swap},
		  * {"add", add},
		 */
		{NULL, ecode}};
	int i = 0;

	while (op[i].opcode != NULL)
	{
		if (!strcmp(s, op[i].opcode))
			return (op[i].f);
		i++;
	}
	return (op[i].f);
}
