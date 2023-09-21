#include "monty.h"

FILE *file;

/**
 * main - executes monty code
 * @argc: argument count
 * @argv: arguments
 *
 * Return: 0 if ran successfuly
*/
int main(int argc, char *argv[])
{
	void (*f_op)(stack_t **stack, unsigned int line_number);
	char *s = NULL, *args[2], *parameter;
	size_t line_count = 0, buffer = 1024;
	stack_t *head = NULL;
	ssize_t line;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	while (1)
	{
		line = getline(&s, &buffer, file);
		if (line == -1)
			break;
		line_count++;
		args[0] = strtok(s, " \n");
		if (!args[0])
			continue;
		else if (strcmp("push", args[0]) == 0)
		{
			parameter = strtok(NULL, " \n");
			push(&head, line_count, parameter);
		}
		else
		{
			f_op = hndl(args[0], line_count, &head);
			if (f_op == NULL)
			{
				fprintf(stderr, "L%ld: unknown instruction %s\n",
					line_count, args[0]), exit(EXIT_FAILURE);
			}
			f_op(&head, line_count);
		}
	}
	fclose(file), free(s), sfree(head);

	return (0);
}
