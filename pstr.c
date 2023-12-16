#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Pointer to a pointer to the stack
 * @line_number: Line number in the file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	if (current == NULL)
	{
		putchar('\n');
		return;
	}

	while (current != NULL && current->n != 0 && current->n >= 0 &&
	current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}
