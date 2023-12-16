#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Pointer to a pointer to the stack
 * @line_number: Line number in the file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)line_number;

	/* Check if the stack is empty or has only one element */
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	/* Save the current top element of the stack in temp */
	temp = *stack;

	/* Move temp to the last element of the stack */
	while (temp->next != NULL)
		temp = temp->next;

	/* Save the second-to-last element in last */
	last = temp->prev;

	/* Disconnect temp from the rest of the stack */
	last->next = NULL;
	temp->prev = NULL;

	/* Connect temp to the top of the stack */
	temp->next = *stack;
	(*stack)->prev = temp;

	/* Update the stack pointer to point to temp, which is now the new top */
	*stack = temp;
}
