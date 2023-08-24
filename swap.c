#include "monty.h"
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file where swap
 * is called
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int t;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	t = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = t;
}
