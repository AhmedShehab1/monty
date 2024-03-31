#include "monty.h"
/**
 * pop - Removess Top Node
 * Usage: pop
 * @stack: Pointer To Top Element Of Stack
 * @line_number: Current Line In Monty ByteCode File
 *
 * Return: popped Item
*/
void pop(stack_t **stack, int line_number)
{
	stack_t *temp = NULL;

	if (!isEmpty(*stack))
	{
		temp = *stack;
		*stack = (*stack)->next;
		if (temp->next != NULL)
			temp->next->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * swap - swaps the top two elements of the stack.
 * Usage: swap
 * @stack: Top Node Of Stack
 * @line_number: Current Line In Monty ByteCode File
 *
*/
void swap(stack_t **stack, int line_number)
{
	int temp;

	if (!isEmpty(*stack))
	{
		if ((*stack)->next != NULL)
		{
			temp = (*stack)->n;
			(*stack)->n = (*stack)->next->n;
			(*stack)->next->n = temp;
			return;
		}
	}
	free_stack(stack);
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * add - adds the top two elements of the stack.
 * Usage: add
 * @stack: Top Node Of Stack
 * @line_number: Current Line In Monty ByteCode File
 *
*/
void add(stack_t **stack, int line_number)
{
	if (!isEmpty(*stack))
	{
		if ((*stack)->next != NULL)
		{
			(*stack)->next->n = (*stack)->n + (*stack)->next->n;
			pop(stack, line_number);
			return;
		}
	}
	free_stack(stack);
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * nop - No Operation (Stall) - (Do Nothing)
 * Usage: nop
 * @stack: Top Node Of Stack
 * @line_number: Current Line In Monty ByteCode File
*/
void nop(stack_t **stack, int line_number)
{
	__UNUSED_PARAM(stack);
	__UNUSED_PARAM(line_number);
}
/**
 * sub - subtracts the top element of the stack from the
 * second top element of the stack.
 * Usage: sub
 * @stack: Top Node Of Stack
 * @line_number: Current Line In Monty ByteCode File
*/
void sub(stack_t **stack, int line_number)
{
	if (!isEmpty(*stack))
	{
		if ((*stack)->next != NULL)
		{
			(*stack)->next->n = (*stack)->next->n - (*stack)->n;
			pop(stack, line_number);
			return;
		}
	}
	free_stack(stack);
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
