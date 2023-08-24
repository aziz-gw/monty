#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 *
 * Return: nothing
 */

void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *last_out;
	stack_t *second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last_out = *stack;
	while (last_out->next != NULL)
		last_out = last_out->next;

	second_last = last_out->prev;

	last_out->next = *stack;
	(*stack)->prev = last_out;
	(*stack)->next = NULL;

	second_last->next = NULL;
	last_out->prev = NULL;

	*stack = last_out;
}
