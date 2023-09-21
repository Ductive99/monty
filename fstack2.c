#include "monty.h"

/**
 * swap - swaps the values of the top 2 elements of a stack
 * @stack: pointer to pointer to stack
 * @line_number: line number in execution
 *
 * Return: void
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		fclose(file);
		sfree(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * nop - doesn't do anything
 * @stack: pointer to pointer to a stack
 * @line_number: line number in execution
 *
 * Return: void
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
