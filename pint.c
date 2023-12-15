#include "monty.h"
/**
 * pint - Prints the value at the top of the stack
 * @stack: A pointer to the pointer to the top of the stack
 * @line_number: Line number in the file
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
