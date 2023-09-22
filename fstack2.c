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

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to pointer to the stack
 * @line_number: line number in execution
 *
 * Return: void
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty", line_number);
		fclose(file);
		sfree(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range", line_number);
		fclose(file);
		sfree(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (char)(*stack)->n);
}

/**
 * pstr - prints the string starting from the top of the stack
 * @stack: pointer to pointer to the stack
 * @line_number: line number in execution
 *
 * Return: void
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current)
	{
		if (current->n == 0)
			break;
		else if (current->n < 0 || current->n > 127)
			break;
		else if (!current)
			break;

		printf("%c", (char)current->n);

		current = current->next;
	}
	printf("\n");
}
