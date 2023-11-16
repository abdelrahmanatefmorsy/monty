#include "monty.h"
/**
 * translate - function that translate program for the true function
 * @line : line of file
 * @str : string
 * @start: stack
 * @buffer: buffer array
 * Return : 0
 */
void translate(char *str, unsigned int line, stack_t **start, char *buffer)
{
	int i;
	char *strline = tostr(line);

	instruction_t check[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	};
	for (i = 0; i < 2; i++)
	{
		if (comp(str, check[i].opcode))
		{
			check[i].f(str, line);
			return 
		}
	}
	write(2, "L", 1);
	orror(linestr), orror(": unknown instruction "), orro(str), orror("\n");
	free(buffer);
	freest(*start);
	free(linestr);
	exit(EXIT_FAILURE);
}
