#include "monty.h"

/**
 * find_instruction - Finds the instruction function for a given opcode.
 * @instructions: The Monty instruction set.
 * @opcode: The opcode to find.
 * Return: The corresponding instruction function or NULL if not found.
 */
instruction_t *find_instruction(instruction_t *instructions,
		const char *opcode)
{
	int i = 0;

	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return (&(instructions[i]));
		i++;
	}
	return (NULL);
}

