#include "monty.h"
/**
 * monty_push - Adds a new node at the begining of a stack
 * @monty_stack: Pointer to a pointer to the stack
 * @value: Value to be added
 * @line_number: Line number in the file
 */

void monty_push(stack_t **monty_stack, int value, unsigned int line_number)
{
	stack_t *new_node;

	new_node = (stack_t *)mallco(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "L%d: Error: malloc failed\n, line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new->prev = NULL;
	new_node->next = *monty_stack;

	if (*monty_stack != NULL)
	{
		(*monty_stack->prev = new_node;
	}
}
