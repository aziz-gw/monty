#include "monty.h"
/**
 * pop - removes the top element of the stack.
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file where
 * pint is called
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * _pop - removes the top element of the stack.
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file where
 * pint is called
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	if (mode == MODE_STACK)
		pop(stack, line_number);
	else if (mode == MODE_QUEUE)
		dequeue(stack, line_number);
}
