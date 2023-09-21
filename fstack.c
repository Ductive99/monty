#include "monty.h"

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

/**
 * push - function that pushes an element to the (top of the) stack
 * @stack: pointer to the (top of the) stack
 * @line_number: line number in execution
 * @parameter: parameter for the push function
 *
 * Return: void
*/
void push(stack_t **stack, unsigned int line_number, char *parameter)
{
	stack_t *new;

	(void)line_number;

	if (parameter == NULL || _isdigit(parameter) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(file);
		sfree(*stack);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(parameter);
	new->next = NULL;
	new->prev = NULL;
	if (*stack)
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	*stack = new;
}

/**
 * pall - Prints ALL elements of a stack
 * @stack: pointer to the (top of the) stack
 * @line_number: line number in execution
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;

	while (current)
	{
		printf("%d", current->n);
		current = current->next;
		printf("\n");
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to pointer to (top of the) stack
 * @line_number: line number in execution
 *
 * Return: void 
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	(void)line_number;

	printf("%d\n", (*stack)->n);
}
