#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>
#include <limits.h>
#include "lib.h"
/**
 * _atoi - Converts a string to an integer.
 * @s: The input string to be converted.
 * Return: The integer value converted from the string.
 */
int _atoi(char *s)
{
	int i = 0, sign = 1;
	long result = 0;

	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');

		if (result * sign > INT_MAX || result * sign < INT_MIN)
		{
			return (sign == 1 ? INT_MAX : INT_MIN);
		}

		i++;
	}

	return (result * sign);
}

/**
 * _strncpy - Copies up to 'n' characters from the source to the destination.
 * @destination: The destination string to which characters are copied.
 * @source: The source string from which characters are copied.
 * @n: The maximum number of characters to be copied.
 * Return: A pointer to the start of the destination string.
 */
char *_strncpy(char *destination, const char *source, int n)
{
	int i, j;
	char *start = destination;

	i = 0;
	while (source[i] != '\0' && i < n - 1)
	{
		destination[i] = source[i];
		i++;
	}

	if (i < n)
	{
		j = i;
		while (j < n)
		{
			destination[j] = '\0';
			j++;
		}
	}

	return (start);
}
