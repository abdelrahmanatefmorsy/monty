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
