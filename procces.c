#include"monty.h"
/**
 * _sub - sub 2 elements of stack
 * @stack: top
 * @line: line number
 */
void _sub(stack_t **stack, unsigned int line)
{
	char *str = tostr(line);
	stack_t *ptr;

	if (lenst(stack) < 2)
	{
		orror("L"), orror(str), orror(": can't sub, stack too short\n");
		free(str);
		freest(*stack);
		exit(EXIT_FAILURE);
	}
	free(str);
	ptr = (*stack)->next;
	ptr->n -= (*stack)->n;
	free(*stack);
	*stack = ptr;
}
/**
 * _add - add 2 elements of stack
 * @stack: top
 * @line: line number
 */
void _add(stack_t **stack, unsigned int line)
{
	char *str = tostr(line);
	stack_t *ptr;

	if (lenst(stack) < 2)
	{
		orror("L"), orror(str), orror(": can't add, stack too short\n");
		free(str);
		freest(*stack);
		exit(EXIT_FAILURE);
	}
	free(str);
	ptr = (*stack)->next;
	ptr->n += (*stack)->n;
	free(*stack);
	*stack = ptr;
}
/**
 * _mul - mul 2 elements of stack
 * @stack: top
 * @line: line number
 */
void _mul(stack_t **stack, unsigned int line)
{
	char *str = tostr(line);
	stack_t *ptr;

	if (lenst(stack) < 2)
	{
		orror("L"), orror(str), orror(": can't mul, stack too short\n");
		free(str);
		freest(*stack);
		exit(EXIT_FAILURE);
	}
	free(str);
	ptr = (*stack)->next;
	ptr->n *= (*stack)->n;
	free(*stack);
	*stack = ptr;
}
