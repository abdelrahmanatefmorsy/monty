#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - main function of project
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 success
 */
int main(int argc, char *argv[])
{
	FILE *ptrfile;
	char *buffer = NULL;
	char *strget = NULL, *ar0 = NULL;
	unsigned int line = 0, or;
	size_t size = 0;
	stack_t *start = NULL;

	if (argc != 2)
	{
		ar0 = malloc(_strlen(argv[0]));
		for (or = 2; argv[0][or]; or++)
			ar0[or - 2] = argv[0][or];
		ar0[or - 2] = '\0';
		orror("USAGE: "), orror(ar0), orror(" file\n");
		free(ar0);
		return (EXIT_FAILURE);
	}
	ptrfile = fopen(argv[1], "r");
	if (ptrfile == NULL)
	{
		orror("Error: Can't open file ");
		orror(argv[1]), orror("\n");
		return (EXIT_FAILURE);
	}
	while (getline(&buffer, &size, ptrfile) != -1)
	{
		line++;
		strget = strtok(buffer, "\r\t\n ");
		if (!strget)
			continue;
		if (comp(strget, "queue"))
			continue;
		if (strget[0] == '#')
			continue;
		translate(strget, line, &start, buffer);
	}
	free(buffer);
	fclose(ptrfile);
	freest(start);
	return (EXIT_SUCCESS);
}
/**
 * orror- print error in stderr
 * @err : ther error will print
 * Return : 0:
 */
void orror(char *err)
{
	write(2, err, _strlen(err));
}
/**
 * freest - free function
 * @stack: stack will free
 */
void freest(stack_t *stack)
{
	stack_t *ptr;

	while (stack)
	{
		ptr = stack;
		stack = stack->next;
		free(ptr);
	}
}
