#include "monty.h"

/**
 * rotl - Rotates the stack to the top
 * @stack: Pointer to a pointer to the stack
 * @line_number: Line number in the file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	/* Check if the stack is empty or has only one element */
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	/* Save the current top of the stack in temp */
	temp = *stack;

	/* Update the stack to point to the second element */
	*stack = (*stack)->next;
	(*stack)->prev = NULL;  /* Disconnect temp from the new top */

	/* Find the last node in the updated stack */
	last = *stack;
	while (last->next != NULL)
		last = last->next; /* Move to the last node */

	/* Make the original top of the stack the last node */
	temp->prev = last;   /* Connect temp to the new last node */
	temp->next = NULL;   /* Set temp as the new top of the stack */
}
