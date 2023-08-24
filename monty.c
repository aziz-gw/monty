#include "monty.h"
#include <stdio.h>

/* Global variable */

int mode = MODE_STACK;

/**
 * main - Entry point of the Monty interpreter
 * @argc: count
 * @argv: argument vector
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL, *temp;
	FILE *file;
	char line[1024], *opcode;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		if (line[0] == '#' || line[0] == '\n')
			continue;
		
		opcode = strtok(line, " \t\n");
		/* if empty */
		if (opcode == NULL)
			continue;
		if (strcmp(opcode, "#") == 0)
			continue;

		if (strcmp(opcode, "push") == 0)
			_push(&stack, line_number);
		else if (strcmp(opcode, "pall") == 0)
			pall(&stack, line_number);
		else if (strcmp(opcode, "pint") == 0)
			pint(&stack, line_number);
		else if (strcmp(opcode, "pop") == 0)
			_pop(&stack, line_number);
		else if (strcmp(opcode, "swap") == 0)
			swap(&stack, line_number);
		else if (strcmp(opcode, "add") == 0)
			add(&stack, line_number);
		else if (strcmp(opcode, "nop") == 0)
			nop(&stack, line_number);
		else if (strcmp(opcode, "sub") == 0)
			sub(&stack, line_number);
		else if (strcmp(opcode, "div") == 0)
			_div(&stack, line_number);
		else if (strcmp(opcode, "mul") == 0)
			mul(&stack, line_number);
		else if (strcmp(opcode, "mod") == 0)
			mod(&stack, line_number);
		else if (strcmp(opcode, "pstr") == 0)
			pstr(&stack, line_number);
		else if (strcmp(opcode, "pchar") == 0)
			pchar(&stack, line_number);
		else if (strcmp(opcode, "rotl") == 0)
                        rotl(&stack, line_number);
		else if (strcmp(opcode, "rotr") == 0)
                        rotr(&stack, line_number);
		else if (strcmp(opcode, "queue") == 0)
			queue(&stack, line_number);
		else if (strcmp(opcode, "stack") == 0)
			_stack(&stack, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
					line_number, opcode);
			while (stack != NULL)
			{
				temp = stack;
				stack = stack->next;
				free(temp);
			}
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	fclose(file);
	exit(EXIT_SUCCESS);
}
