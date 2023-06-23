#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern char *argument;
char **tokenizer(char *buffer);
void (*select_func(char *s, unsigned int))(stack_t **, unsigned int);
char *_strdup(char *str);
unsigned int check_mode(char *str);
void error(char *buf, char **tokens, unsigned int line, stack_t *h, FILE *fd);


void free_linkedlist(stack_t *head);
void free_tok(char **tokens);
int is_integer(const char *input);
void validate_arg(int argc);
void cant_open(char *s);

void mod(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pushend(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void divi(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void mul_nodes(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line);
void pstr(stack_t **stack, unsigned int line);
void rotl(stack_t **stack, unsigned int line);
void rotr(stack_t **stack, unsigned int line);
#endif
