#include "monty.h"
/**
 * pstr - prints the string starting
 * at the top of the stack
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the file where pchar is called.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;

	while (current != NULL)
	{
		if (current->n <= 0 || current->n > 127)
			break;

		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
