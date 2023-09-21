#include "monty.h"
#include <stdio.h>

/**
 * fhandle - links operators to their functions
 * @op: the operator
 * @line: line count
 * @stack: pointer to pointer to the stack
 *
 * Return: the corresponding function
*/
void (*fhandle(char *op, unsigned int line, stack_t **stack))(stack_t**, unsigned int)
{
	int i;
	instruction_t operation[] = {
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; operation[i].opcode; i++)
	{
		if (strcmp(operation[i].opcode, op) == 0)
			return (operation[i].f);
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line, op);
	fclose(file);
	sfree(*stack);
	exit(EXIT_FAILURE);
}

/**
 * sfree - frees a stack
 * @stack: pointer to the stack
 *
 * Return: void
*/
void sfree(stack_t *stack)
{
	if (stack)
	{
		sfree(stack->next);
		free(stack);
	}
}
