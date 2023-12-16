#include "monty.h"

/**
 * monty_mul - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer to the stack
 * @line_number: Line number in the file
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	int product;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	product = (*stack)->next->n * (*stack)->n;

	/* Update the second top element with the result */
	(*stack)->next->n = product;

	/* Pop the top element */
	pop(stack, line_number);
}
