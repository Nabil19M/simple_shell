#include "lib.h"

/**
 * main - entry point for a simple shell program
 * @ac: the number of arguments (unused)
 * @av: an array of strings containing the program arguments
 * Return: the exit status of the program
 */
int main(int ac __attribute__((unused)), char *av[])
{
	char *buffer;
	size_t bufsize = 0;
	int cnt = 1;
	int r = EXIT_SUCCESS;
	pid_t procid;

	while (1)
	{
		write(1, "GG$ ", 4);
		if (getline(&buffer, &bufsize, stdin) == EOF)
		{
		_putchar('\n');
		break;
		}
	buffer[_strcspn(buffer, "\n")] = 0;

	if (_strcmp(buffer, "exit") == 0)
		break;

	procid = fork();

	if (procid == -1)
		exit(EXIT_FAILURE);

	else if (procid == 0)
	{
		if (_strcmp(buffer, "env") == 0)
		{
			print_env();
		}

		execute_command(buffer, av, cnt);
	}
	else
		wait(NULL);
	cnt++;
	}
	return (r);
}
