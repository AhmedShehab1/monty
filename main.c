#include "monty.h"
/**
 * main - Entry Point Of The Program
 * @argc: Count Of Command Line Arguments
 * @argv: Pointer To Command Line Argument
 *
 * Return: Always 0
*/
int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = malloc(BUFFER_SIZE);
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, BUFFER_SIZE, stream))
	{
		line_number++;
		if (getOpCode(&head, line))
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(&head);
	free(line);
	fclose(stream);
	return (0);
}
