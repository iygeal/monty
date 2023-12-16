#include "monty.h"

/**
 * monty_mod - Computes the rest of the division of the second top element
 *              by the top element.
 * @stack: Pointer to a pointer to the stack
 * @line_number: Line number in the file
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	int divisor, dividend, remainder;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
		}

	divisor = (*stack)->n;
	dividend = (*stack)->next->n;

	if (divisor == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	remainder = dividend % divisor;

	/* Update the second top element with the remainder */
	(*stack)->next->n = remainder;

	/* Pop the top element */
	pop(stack, line_number);
}
