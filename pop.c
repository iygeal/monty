#include "monty.h"

/**
 * pop - This function removes the top element of the stack
 * @stack: Pointer to a pointer to the stack
 * @line_number: Line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp; /* Temporary pointer to hold stack */

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	/* Save the top element in temporary pointer */
	temp = *stack;

	/* Move the stack pointer to the next element */
	*stack = (*stack)->next;

	/* Update the previous pointer if the stack is not empty */
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;  /* Effectively removed */
	}

	/* Free the removed element */
	free(temp);
}
