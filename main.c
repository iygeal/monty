#include "monty.h"

/**
 * main - Entry pointy for the Monty Interpreter
 * @argc: Argument counter
 * @argv: Argument vector
 * Return: 0 = Success
 */
int main(int argc, char argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stack_t *monty_stack = NULL;
	char opcode[256];
	int arg;
	unsigned int line_number = 0;

	while (fscanf(file, "%s", opcode) != EOF)
	{
		line_number++;
		if (strcmp(opcode, "push") == 0)
		{
			if (fsacnf(file, "%d", &arg) == 0)
			{
				fprintf(stderr, "L%d: Error: usage: push integer\n", line_number);
				exit(EXIT_FAILUE);
			}
			monty_push(&monty_stack, arg, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			monty_pall(&monty_stack, line_number);
		}
		else
		{
			fptintf(stderr, "L%d: Error: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	return (0);
}
