#include "monty.h"

/**
 * queue - queue opcode
 * @stack: Double pointer to the front
 * @line_number: current line number
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = MODE_QUEUE;
}

/**
 * dequeue - Removes the front element from the queue
 * @queue: Double pointer to the front of the queue
 * @n: line number
 */
void dequeue(stack_t **queue, unsigned int n)
{
	stack_t *temp;

	(void)n;

	if (*queue == NULL)
	{
		exit(EXIT_FAILURE);
	}

	temp = *queue;
	*queue = (*queue)->next;
	free(temp);
}

/**
 * enqueue - Adds an element to the back of the queue
 * @queue: Double pointer to the front of the queue
 * @n: line number
 */
void enqueue(stack_t **queue, unsigned int n)
{
	char *arg = strtok(NULL, " \t\n");
	stack_t *new, *temp;

	if (arg == NULL || !is_numeric(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", n);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(arg);
	new->next = NULL;

	if (*queue == NULL)
		*queue = new;
	else
	{
		temp = *queue;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}
