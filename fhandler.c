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
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"nop", nop},
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

/**
 * _isdigit - checks whether a string is a number
 * @str: the string
 *
 * Return: 1 -> if it's a number
 * ------- 0 -> if not
*/
int _isdigit(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;

	for (; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (0);

	return (1);
}
