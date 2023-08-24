#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file where push is called
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");
	stack_t *new; /* New stack node */

	if (arg == NULL || !is_numeric(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		/* Case of error */
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(arg);
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new;

	*stack = new;
}

/**
 * _push - pushes an element onto the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file where push is called
 */
void _push(stack_t **stack, unsigned int line_number)
{
	if (mode == MODE_STACK)
		push(stack, line_number);
	else if (mode == MODE_QUEUE)
		enqueue(stack, line_number);
}
