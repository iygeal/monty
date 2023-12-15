#include "monty.h"

/**
 * div - Divides the second top element of the stack by the top element.
 * @stack: Pointer to a pointer to the stack
 * @line_number: Line number in the file
 */
void div(stack_t **stack, unsigned int line_number)
{
	int ratio;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	ratio = (*stack)->next->n / (*stack)->n;

	/* Update the second top element with the result */
	(*stack)->next->n = ratio;

	/* Pop the top element */
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
