#include "monty.h"

/**
 * add - adds the two top elements of a stack
 * @stack: pointer to pointer to the stack
 * @line_number: line number in execution
 *
 * Return: void
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		fclose(file);
		sfree(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * sub - substract the top element from the second top one
 * @stack: pointer to pointer to the stack
 * @line_number: line number in execution
 *
 * Return: void
*/
void sub(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		fclose(file);
		sfree(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - multiples the two top elements of a stack
 * @stack: pointer to pointer to the stack
 * @line_number: line number in execution
 *
 * Return: void
*/
void mul(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		fclose(file);
		sfree(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * divide - divides the 2nd top element by the top element of a stack
 * @stack: pointer to pointer to the stack
 * @line_number: line number in execution
 *
 * Return: void
*/
void divide(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		fclose(file);
		sfree(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		fclose(file);
		sfree(*stack);
		exit(EXIT_FAILURE);	
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mod - computes the rest of div() operation
 * @stack: pointer to pointer to the stack
 * @line_number: line number in execution
 *
 * Return: void
*/
void mod(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		fclose(file);
		sfree(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		fclose(file);
		sfree(*stack);
		exit(EXIT_FAILURE);	
	}	

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
