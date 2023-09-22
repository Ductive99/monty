#include "monty.h"

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
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		fclose(file);
		sfree(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
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

/**
 * rotl - rotates the top of the stack to the bottom
 * @stack: pointer to pointer to the stack
 * @line_number: line number in execution
 *
 * Return: void
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *temp = *stack;

	if (!(*stack) || !(*stack)->next)
		return;
	
	while (temp->next)
	{
		temp = temp->next;
	}
	top->prev = temp;
	temp->next = top;
	*stack = top->next;
	(*stack)->prev = NULL;
	top->next = NULL;	
}
