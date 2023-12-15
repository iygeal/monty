#include "monty.h"
/**
 * main - Entry pointy for the Monty Interpreter
 * @argc: Argument counter
 * @argv: Argument vector
 * Return: 0 = Success
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	interpret_file(argv[1]);

	return (EXIT_SUCCESS);
}
