#include "monty.h"
/**
 * free_stack - Frees a stack
 * @head: Pointer To First Node
 *
*/
void free_stack(stack_t **head)
{
	stack_t *temp = NULL;

	while (*head != NULL)
	{
		temp = (*head);
		(*head) = (*head)->next;
		free(temp);
	}
}
