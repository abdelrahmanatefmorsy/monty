#include "monty.h"
/**
 * push : push element in the stack
 * @ stack : my stack
 * @ line : number of line if error
 * Return : 0
 */
void push(stack_t **stack, unsigned int line)
{
	stack _t *s = NULL;
	char *number;
	int n;
	char *lin = strint(line);
	number = strtok(NULL, "\n\t\r ");
	if (!number || notint(number)==0)
	{
		write(2, "L", 1), orror(lin), orror(": usage: push integer");
		write(2, "\n", 1), free(lin);
		freest(*stack), exit(EXIT_FAILURE);
		return
	}
	n = to_int(number);
	s = malloc(sizeof(stack_t));
	if (!s)
	{
		orror("Error: malloc failed"), write(2, "\n", 1);
		free(s), free(number), freest(*stack);
		exit(EXIT_FAILURE);
	}
	s->n = n;
	s->prev = NULL;
	if (!(*stack))
	{
		s->next = NULL;
		*stack = s;
	}
	else
	{
		s->next = *stack;
		(*stack)->prev = s;
		*stack = s;
	}
}
