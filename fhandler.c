#include "monty.h"
#include <stdio.h>

/**
 * hndl - links operators to their functions
 * @o: the operator
 * @l: line count
 * @pile: pointer to pointer to the stack
 *
 * Return: the corresponding function
*/
void (*hndl(char *o, unsigned int l, stack_t **pile))(stack_t**, unsigned int)
{
	int i;
	instruction_t operation[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};

	for (i = 0; operation[i].opcode; i++)
	{
		if (strcmp(operation[i].opcode, o) == 0)
			return (operation[i].f);
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", l, o);
	fclose(file);
	sfree(*pile);
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
