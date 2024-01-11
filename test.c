#include "lib.h"

/**
 * main - entry point for a simple shell program
 * @ac: the number of arguments (unused)
 * @av: an array of strings containing the program arguments
 * Return: the exit status of the program
 */
int main(int ac __attribute__((unused)), char *av[])
{
	char buffer[BUFFER_SIZE];
	int cnt = 1;
	int r = EXIT_SUCCESS;

	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(buffer, sizeof(buffer), stdin) == NULL)
		{
		printf("\n");
		break;
		}
	buffer[_strcspn(buffer, "\n")] = 0;

	if (_strcmp(buffer, "exit") == 0)
		break;

	pid_t procid = fork();

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
	{
		wait(NULL);
	}

	cnt++;
	}
	return (r);
}
