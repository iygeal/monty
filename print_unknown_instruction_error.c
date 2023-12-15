#include "monty.h"

/**
 * print_unknown_instruction_error - Prints an error message
 * for an unknown opcode.
 * @line_number: The line number in the Monty bytecode file.
 * @opcode: The unknown opcode.
 */
void print_unknown_instruction_error(unsigned int line_number,
		const char *opcode)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

