#include "monty.h"

/**
 * pall - prints all values on the stack
 * @stack: double pointer to the top of stack
 * @line_number: Line number in the file where pall is called.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
