#include "monty.h"
/**
 * main - Entry pointy for the Monty Interpreter
 * @argc: Argument counter
 * @argv: Argument vector
 * Return: 0 = Success
 */
int main(int argc, char *argv[])
{
	stack_t *monty_stack = NULL;
	char opcode[256];
	int arg;
	unsigned int line_no = 0;
	FILE *file = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	while (fscanf(file, "%s", opcode) != EOF)
	{
		line_no++;
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &arg) == 0)
			{
				fprintf(stderr, "L%d: Error: usage: push integer\n", line_no);
				exit(EXIT_FAILURE);
			}
			monty_push(&monty_stack, arg, line_no);
		}
		else if (strcmp(opcode, "pall") == 0)
			monty_pall(&monty_stack);
		else
		{
			fprintf(stderr, "L%d: Error: unknown instruction %s\n", line_no, opcode);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	return (0);
}
