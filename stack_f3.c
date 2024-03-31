#include "monty.h"

/**
 * __div - divides the second top element of the stack
 * by the top element of the stack.
 * Usage: div
 * @stack: Top Node Of Stack
 * @line_number: Current Line In Monty ByteCode File
*/
void __div(stack_t **stack, int line_number)
{
	if (isEmpty(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
}
/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * Usage: mul
 * @stack: Top Node Of Stack
 * @line_number: Current Line In Monty ByteCode File
*/
void mul(stack_t **stack, int line_number)
{
	if (isEmpty(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->n * (*stack)->next->n;
	pop(stack, line_number);
}
/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * Usage: mod
 * @stack: Top Node Of Stack
 * @line_number: Current Line In Monty ByteCode File
*/
void mod(stack_t **stack, int line_number)
{
	if (isEmpty(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
}
