#include "monty.h"
/**
 * _stack - stack opcode
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the file where push is called
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = MODE_STACK;
}
