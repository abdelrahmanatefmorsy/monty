#include "monty.h"

/**
 * _strlen- entry point
 *
 * @s: saged
 *
 *
 * * Return: size of @s
 */

int _strlen(char *s)
{
	int p = 0;

	for (; *s != '\0'; s++)
		p++;
	return (p);
}
/**
 * comp- function compare two string
 * @s1: first string
 * @s2: second string
 * Return: 1 or 0
 */
int comp(char *s1, char *s2)
{
	int i;

	if (_strlen(s1) != _strlen(s2))
		return (0);
	for (i = 0; s1[i] && s2[i]; i++)
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

/**
 * tostr - function that translate intger to string
 * @number: the number
 * Return: 0
 */
char *tostr(int number)
{
	char *str, *str2;
int i = 0, j = 0, z = 1;

	str = malloc(sizeof(char) * 100000);
	if (number == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (number < 0)
	{
		number *= -1;
		z = 0;
	}
	while (number != 0)
	{
		str[i] = (number % 10) + '0';
		number /= 10;
		i++;
	}
	i--;
	str2 = malloc(_strlen(str) + 2);
	if (z == 0)
	{
		str2[0] = '-';
		j = 1;
	}
	while (i >= 0)
	{
		str2[j] = str[i];
		j++;
		i--;
	}
	str2[j] = '\0';
	return (str2);
}
