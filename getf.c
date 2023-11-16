#include "monty.h"
/**
 * translate - function that translate program for the true function
 * @line : line of file
 * @str : string
 * @start: stack
 * @buffer: buffer array
 * Return : 0
 */
void translate(char *str, unsigned int line, stack_t **start)
{
	int i;
	char *strline = tostr(line);

	instruction_t check[] = {
		{"push", _push},
		{"pall", _pall},
		{"pop", _pop}
	};

	for (i = 0; i < 3; i++)
	{
		if (comp(str, check[i].opcode))
		{
			check[i].f(start, line);
			return;
		}
	}
	write(2, "L", 1);
	orror(strline), orror(": unknown instruction "), orror(str), orror("\n");
	freest(*start);
	free(strline);
	exit(EXIT_FAILURE);
}
