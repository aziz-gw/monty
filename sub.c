#include "monty.h"
/**
 * sub - subs the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the file where add is called.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
