#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @stack: pointer to the top of the stack.
 * @line_number: line number in the file.
 *
 * Return: nothing
 */

void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *top;
	stack_t *second_top;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	top = *stack;
	second_top = top->next;

	while (top->next != NULL)
		top = top->next;

	top->next = *stack;
	(*stack)->prev = top;
	(*stack)->next = NULL;

	*stack = second_top;
	second_top->prev = NULL;
}
