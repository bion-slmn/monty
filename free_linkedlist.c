#include "monty.h"
/**
  * free_linkedlist - frees the linked list
  * @head: head of stack
  * Return: Void
  */
void free_linkedlist(stack_t *head)
{
	stack_t *tmp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
