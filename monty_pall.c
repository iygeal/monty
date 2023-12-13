#include "monty.h"
/**
 * monty_pall - Prints all the values on a stack
 * @monty_stack: Pointer to a pointer to the stack
 * @line_number: Line number in the file
*/
void monty_pall(stack_t **monty_stack, unsigned int line_number)
{
	stack_t *current = *monty_stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
