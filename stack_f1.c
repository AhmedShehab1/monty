#include "monty.h"
/**
 * newNode - Creates New Node
 * @n: Item To Be Stored
 *
 * Return: New Node
*/
stack_t *newNode(int n)
{
	stack_t *stackNode = malloc(sizeof(stack_t));

	if (stackNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	stackNode->n = n;
	return (stackNode);
}
/**
 * isEmpty - Checks Wether a Given stack is empty or not
 * @stack: Top Node Of Stack
 *
 * Return: Non-Zero if Empty OR 0 If not Empty
*/
int isEmpty(stack_t *stack)
{
	return (!stack);
}
/**
 * push - Pushes New Element To The Top Of Stack
 * @stack: Pointer To Top Node Of Stack
 * @n: New Item To Be Added
 *
*/
void push(stack_t **stack, int n)
{
	stack_t *stackNode = newNode(n);

	stackNode->next = *stack;
	*stack = stackNode;
	if (stackNode->next != NULL)
		stackNode->next->prev = stackNode;
	stackNode->prev = NULL;
}
/**
 * pall - Print All Items in Stack
 * @stack: Top Node Of Stack
 * @line_number: Current Line In Monty ByteCode File
 *
*/
void pall(stack_t **stack, int line_number)
{
	stack_t *temp = NULL;

	__UNUSED_PARAM(line_number);
	if (!isEmpty(*stack))
	{
		temp = *stack;
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}
/**
 * pint - Prints Top Item Of Stack
 * @stack: Top Node Of Stack
 * @line_number: Current Line In Monty ByteCode File
 *
*/
void pint(stack_t **stack, int line_number)
{
	if (!isEmpty(*stack))
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
