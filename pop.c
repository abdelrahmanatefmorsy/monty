#include"monty.h"
/**
 * _pop - pop in the stack
 * @stack: my stack
 * @line: line number
 */
void _pop(stack_t **stack, unsigned int line)
{
	char *str = tostr(line);
	stack_t *ptr;

	if (!(*stack))
	{
		write(2, "L", 1);
        orror(str);
        orror(": can't pop an empty stack");
        orror("\n");
		free(str);
		freest(*stack);
		exit(EXIT_FAILURE);
	}
	free(str);
	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);
}
