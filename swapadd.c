#include "monty.h"
/**
 * lenst - the size of the stack
 * @start: the start of stack
 * Return: 0
 */
int lenst(stack_t **start)
{
	stack_t *ptr = *start;
	int i = 0;

	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
/**
 * _swap - swap
 * @stack: my stack
 * @line: line number
 * Rerun: 0
 */
void _swap(stack_t **stack, unsigned int line)
{
	char *str = tostr(line);
	stack_t *ptr, *ptr2;

	if (lenst(stack) < 2)
	{
		orror("L"), orror(str), orror(": can't swap, stack too short\n");
		free(str);
		freest(*stack);
		exit(EXIT_FAILURE);
	}
	free(str);
	ptr2 = (*stack)->next;
	ptr = (*stack)->next->next;
	(*stack)->next->next = (*stack);
	(*stack)->next = ptr;
	*stack = ptr2;
}
/**
 * _nop - nop
 * @stack: my stack
 * @line: number line
 */
void _nop(stack_t **stack, unsigned int line)
{
	stack = stack;
	line = line;
}
