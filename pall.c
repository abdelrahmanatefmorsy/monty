#include "monty.h"
/**
 * _pall - function that print stack
 * @stack : my stack
 * @line : number line
 * Return: 0
 */
void _pall(stack_t **stack, unsigned int line)
{
	char *str;
	stack_t *ptr = *stack;

	while (ptr != NULL)
	{
		str = tostr(ptr->n);
		write(1, str, _strlen(str));
		write(1, "\n", 1);
		free(str);
		ptr = ptr->next;
	}
	line = line;
}

/**
 * _pint - print the top of stack
 * @stack: stack
 * @line: line number
 */
void _pint(stack_t **stack, unsigned int line)
{
	char *str = tostr(line);

	if (!(*stack))
	{
		write(2, "L", 1);
		orror(str);
		orror(": can't pint, stack empty\n");
		free(str);
		freest(*stack);
		exit(EXIT_FAILURE);
	}
	free(str);
	str = NULL;
	str = tostr((*stack)->n);
	write(1, str, _strlen(str));
	write(1, "\n", 1);
	free(str);
}
