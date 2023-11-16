#include "monty.h"
/**
 * _push - push element in the stack
 * @stack : my stack
 * @line : number of line if error
 * Return : 0
 */
void _push(stack_t **stack, unsigned int line)
{
	stack_t *s;
	char *number;
	int n;
	char *lin = tostr(line);

	number = strtok(NULL, "\n\t\r ");
	if (!number || notint(number) == 0)
	{
		write(2, "L", 1), orror(lin), orror(": usage: push integer");
		write(2, "\n", 1), free(lin);
		freest(*stack), exit(EXIT_FAILURE);
		return;
	}
	n = _atoi(number);
	s = malloc(sizeof(stack_t));
	if (!s)
	{
		orror("Error: malloc failed"), write(2, "\n", 1);
		free(s);
		free(number);
		freest(*stack);
		exit(EXIT_FAILURE);
	}
	s->n = n;
	if (!(*stack))
	{
		(*stack) = s;
		s->next = NULL;
	}
	else
	{
		s->next = *stack;
		*stack = s;
	}
}
/**
 * notint - check integer
 * @str: string
 * Return: 1 if int 0 for non
 */
int notint(char *str)
{
	int i = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
