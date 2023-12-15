#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to a pointer to the stack
 * @line_number: Line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n; /* Add the top two elements */

	pop(stack, line_number); /* Remove the top element */
}
