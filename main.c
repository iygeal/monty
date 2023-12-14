#include "monty.h"
/**
 * main - Entry pointy for the Monty Interpreter
 * @argc: Argument counter
 * @argv: Argument vector
 * Return: 0 = Success
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char opcode[256];
	int arg;
	unsigned int line_number = 0;
	FILE *file;
	char *err = "Error: unknown instruction";

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fscanf(file, "%s", opcode) != EOF)
	{
		line_number++;
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &arg) == 0)
			{
				fprintf(stderr, "L%d: Error: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			monty_push(&stack, arg, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
			monty_pall(&stack);
		else
		{
			fprintf(stderr, "L%d: %s %s\n", line_number, err, opcode);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	return (0);
}
