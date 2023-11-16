#include "monty.h"

/**
 *_atoi- entry point
 *
 * @s: sagoda
 *
 *
 * * Return: size of @s
 */

int _atoi(char *s)
{
	int i = 0;
	unsigned int j = 0;
	int two = 1;
	int z = 1;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			z *= -1;

		while (s[i] >= '0' && s[i] <= '9')
		{
			two = 0;
			j *= 10;
			j += s[i] - '0';
			i++;
			if (s[i] == '\0')
			{
				j *= z;
				return (j);
			}
		}
		j *= z;
		if (two == 0)
			return (j);
		i++;
	}
	return (j);
}
