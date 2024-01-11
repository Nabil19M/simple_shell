#include "lib.h"
/**
 * isSubstring - checks if a substring is present in a given string
 * @str: the string to search in
 * @sub: the substring to search for
 * Return: 1 if the substring is found, 0 otherwise
 */
int isSubstring(const char *str, const char *sub)
{
	while (*str != '\0')
	{
		const char *strPtr = str;
		const char *subPtr = sub;

		while (*subPtr != '\0' && *strPtr == *subPtr)
		{
			strPtr++;
			subPtr++;
		}

		if (*subPtr == '\0')
		{
			return (1);
		}

		str++;
	}

	return (0);
}

/**
 * get_pth - retrieves the first occurrence of a string in the environment
 * @pth: the string to search for in the environment variables
 * Return: a pointer to the first occurrence of the string in the environment
 */
char *get_pth(const char *pth)
{
	char **envp = environ;
	char *argv = NULL;
	int i = 0;

	while (envp[i] != NULL)
	{
		if (isSubstring(envp[i], pth))
		{
			argv = envp[i];
			break;
		}
		i++;
	}

	return (argv);
}

/**
 * _chpath - checks if a given command contains a path separator '/'
 * @command: the command to check
 * Return: 1 if a path separator is present, 0 otherwise
 */
int _chpath(const char *command)
{
	int i;

	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] == '/')
			return (1);
	}
	return (0);
}

/**
 * _strlen - calculates the length of a string
 * @str: the string to calculate the length of
 * Return: the length of the string
 */
int  _strlen(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _putchar - writes a character to the standard output
 * @ch: the character to be written
 * Return: the number of characters written (1)
 */
int _putchar (char ch)
{
	return (write(STDOUT_FILENO, &ch, 1));
}
