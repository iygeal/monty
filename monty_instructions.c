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
		{NULL, NULL} /* Marks the end of the instruction set */
	};
	return (instructions);
}
