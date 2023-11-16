#include "monty.h"
/**
 * main - main function of project
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 success
 */
int main(int argc, char *argv[])
{
	FILE *ptrfile;
	char *buffer = malloc(10000);
	char *strget, *ar0;
	unsigned int line = 0, or;
	stack_t *start = NULL;

	ar0 = malloc(100000);
	if (argc != 2)
	{
		for (or = 2; argv[0][or]; or++)
			ar0[or - 2] = argv[0][or];
		orror("USAGE: "), orror(ar0), orror("\n");
		return (EXIT_FAILURE);
	}
	ptrfile = fopen(argv[1], "r");
	if (ptrfile == NULL)
	{
		orror("Error: Can't open file");
		orror(argv[1]), orror("\n");
		return (EXIT_FAILURE);
	}
	while (fgets(buffer, 10000, ptrfile))
	{
		line++;
		strget = strtok(buffer, "\t\n\r ");
		if (!strget)
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
