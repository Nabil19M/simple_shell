#include "lib.h"
/**
 * handle_errors - handling errors of the shell.
 * @command:.
 * @program:.
 * @pc:.
 * @error_num:.
 * Return: .
 */
int handle_errors(char **command, char *program[], int pc, int error_num)
{
	int prog_len, cmd_len;

	cmd_len = pc;
	cmd_len = _strlen(command[0]);
	prog_len = _strlen(program[0]);
	if (error_num == 127 || error_num == 126)
	{
		write(STDOUT_FILENO, program[0], prog_len);
		write(STDOUT_FILENO, ": 1", 3);
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, command[0], cmd_len);
		if (error_num == 126)
			write(1, ": Permission denied\n", 20);
		else
			write(1, ": not found\n", 12);
	}
	if (error_num == 2)
	{
		write(STDOUT_FILENO, program[0], prog_len);
		write(STDOUT_FILENO, ": ", 2);
	}
	return (0);
}
/**
 * print_prompt_count - prints an integer.
 * @n: the number to print
 * Return: Amount of digits of the number n
 */
int print_prompt_count(int n)
{
	unsigned int num;
	int cont = 1;

	if (n < 0)
	{
		_putchar('-');
		num = (-1) * n;
	}
	else
		num = n;
	if (num / 10)
	{
		cont += print_prompt_count(num / 10);
	}
	_putchar((num % 10) + '0');
	return (cont);
}
