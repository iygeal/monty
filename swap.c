#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Pointer to a pointer to the stack
 * @line_number: Line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next; /* Points to the next (second) item on the stack */
	(*stack)->next = temp->next; /* Top now points to third item on stack */
	(*stack)->prev = temp; /* Top prev points to temp; temp is now top prev */
	temp->next = *stack; /* temp next now points to top; temp is fully top*/
	temp->prev = NULL; /* temp prev points to NULL; no previous element */
	*stack = temp; /* temp is crowned the top of the stack, officially */
}
