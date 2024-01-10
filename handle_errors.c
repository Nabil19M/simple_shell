#include "lib.h"

int handle_errors(char **command, char *program[], int prompt_count, int error_num)
{
    int prog_len, cmd_len;

    // Calculate the lengths of program name and command
    cmd_len = _strlen(command[0]);
    prog_len = _strlen(program[0]);

    // Check if the error number is 127 or 126
    if (error_num == 127 || error_num == 126)
    {
        // Print the program name
        write(STDOUT_FILENO, program[0], prog_len);

        // Print additional context for the error message
        write(STDOUT_FILENO, " : ", 3);
        print_prompt_count(prompt_count);
        write(STDOUT_FILENO, ": ", 2);
        write(STDOUT_FILENO, command[0], cmd_len);
        write(STDOUT_FILENO, ": ", 2);

        // Print the system error message using perror
        perror(" ");
      /*  if (error_num == 127)
            write(STDOUT_FILENO, "command not found", 18);
        else
            write(STDOUT_FILENO, "Permission denied", 18);*/
    }

    // Check if the error number is 2
    if (error_num == 2)
    {
        // Print the program name
        write(STDOUT_FILENO, program[0], prog_len);

        // Print a colon for simplicity
        write(STDOUT_FILENO, ": ", 2);
    }
}

/**
 * print_integer - prints an integer
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
    return cont;
}
