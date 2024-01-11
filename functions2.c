#include "lib.h"

/**
 * print_env - prints the environment variables to the standard output
 */
void print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * execute_command - executes a command provided in a buffer
 * @buffer: the buffer containing the command
 * @av: array of arguments from the main function
 * @cnt: count number of times that the program is called
 */
void execute_command(char *buffer, char *av[], int cnt)
{
	char *ar_gv[BUFFER_SIZE];
	char *token;
	int i = 1;
	int s;

	token = strtok(buffer, " ");
	ar_gv[0] = token;

	while (token != NULL)
	{
		token = strtok(NULL, " ");
		ar_gv[i] = token;
		i++;
	}

	if (_chpath(ar_gv[0]))
		s = execve(ar_gv[0], ar_gv, environ);

	else
	{
		char *g = f_ex_path(ar_gv[0], av, cnt);
		int r = atoi(g);

		s = execve(g, ar_gv, environ);

		exit(r);
	}
}

/**
 * _strcspn - calculates the length of the initial segment of a string
 *             consisting of characters not in another string
 * @str: the string to search
 * @r: the set of characters to exclude
 * Return: the length of the initial segment of str
 */
size_t _strcspn(const char *str, const char *r)
{
	size_t i;

	for (i = 0; str[i] != '\0'; ++i)
	{
		for (size_t j = 0; r[j] != '\0'; ++j)
		{
			if (str[i] == r[j])
			{
				return (i);
			}
		}
	}
	return (i);
}

/**
 * _strcmp - compares two strings
 * @str1: the first string
 * @str2: the second string
 * Return: 0 if the strings are equal, a nvalue if str1 is less than str2,
 *         and a positive value if str1 is greater than str2
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
		return (*str1 - *str2);
	}
	str1++;
	str2++;
	}

	return (*str1 - *str2);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 * Return: a pointer to the duplicated string or NULL if memory allocation f
 */
char *_strdup(const char *str)
{
	if (str == NULL)
	return (NULL);

	size_t l = 0;

	for (l = 0; str[l] != '\0'; l++)
	{
	}
	char *dup = (char *)malloc(l + 1);

	if (dup != NULL)
	{
		for (size_t i = 0; i < l; i++)
		{
			dup[i] = str[i];
		}
		dup[l] = '\0';
	}
	return (dup);
}
