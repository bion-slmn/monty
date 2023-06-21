#include "monty.h"
/**
 * select_func - selects a function to execute
 * @s: is a string passed to the function
 *
 * Return: a pointer corresponding to string
 */
void (*select_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t op[] = {{"push", push},
		{"pall", pall},
		/**
		  *{"pint", pint},
		  *{"pop", pop},
		  *{"swap", swap},
		  * {"add", add},
		 */
		{"\0", NULL}};
	int i = 0;

	while (op[i].opcode)
	{
		if (!strcmp(s, op[i].opcode))
			return (op[i].f);
		i++;
	}
	return (NULL);
}
