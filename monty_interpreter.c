#include "monty.h"
/**
 * interpret_file - Interprets Monty bytecodes from a file
 * @filename: The name of or path to the Monty bytecode file
 */
void interpret_file(const char *filename)
{
	FILE *file = fopen(filename, "r");
	char line[MAX_LINE_LENGTH];
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t *instructions = monty_instructions();

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		line_number++;
		interpret_instruction(&stack, instructions, line, line_number);
	}
	fclose(file);
	free_stack(stack);
}
/**
 * interpret_instruction - Interprets a single Monty bytecode instruction.
 * @stack: A pointer to the  pointer to the top of the stack.
 * @instructions: The instruction set.
 * @line: The Monty bytecode instruction.
 * @line_number: The line number in the Monty bytecode file
 * where the opcode appears.
 */
void interpret_instruction(stack_t **stack, instruction_t *instructions,
		char *line, unsigned int line_number)
{
	char *opcode = strtok(line, " \t\n");
	instruction_t *instruction;

	if (!opcode || opcode[0] == '#')
		return; /* Ignore all empty lines and comments */
	instruction = find_instruction(instructions, opcode);

	if (!instruction)
		print_unknown_instruction_error(line_number, opcode);
	instruction->f(stack, line_number);
}
