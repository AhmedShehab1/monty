#include "monty.h"
/**
 * getOpCode - Gets The Equivalent Opcode And Executes Corresponding Function
 * @stack: Pointer To Top Node
 * @line: String Containing The Opcode
 *
 * Return: 0 On Success -1 If Opcode Is Invalid
*/
int getOpCode(stack_t **stack, char *line)
{
	char *token = NULL;
	char *endptr;
	long int result;
	int i = 1;

	instruction_t inst_s[] = { {"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop} };
	token = strtok(line, "\n\t ");
	if (token != NULL)
	{
		if (!strcmp(token, inst_s[0].opcode))
		{ token = strtok(NULL, "\n\t ");
			result = strtol(token, &endptr, 10);
			if (*endptr == '\0' || *endptr == '\n')
			{ inst_s[0].f(stack, result);
				return (0);
			}
			else
			{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			while (i < 6)
				{
				if (!strcmp(inst_s[i].opcode, token))
				{
					inst_s[i].f(stack, line_number); }
				i++;
				}
			return (0); }
		return (-1); }
	return (0);
}
