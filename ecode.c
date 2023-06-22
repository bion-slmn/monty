#include "monty.h"
/**
  * ecode - handles printing the error to screen
  * when theres no function to map to
  * @stack: the stack pointer
  * @line_number: line number of error
  */
void ecode(stack_t __attribute__((unused)) **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction\n", line_number);
	exit(EXIT_FAILURE);
}
