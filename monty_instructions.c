#include "monty.h"
/**
 * monty_instructions - Returns the Monty instruction set.
 * Return: The Monty instruction set.
 */
instruction_t *monty_instructions(void)
{
	static instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{NULL, NULL} /* Marks the end of the instruction set */
	};
	return (instructions);
}
