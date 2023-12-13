#include "monty.h"
/**
 * monty_pall - Prints all the values on a stack
 * @monty_stack: Pointer to a pointer to the stack
*/
void monty_pall(stack_t **monty_stack)
{
	stack_t *current = *monty_stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
