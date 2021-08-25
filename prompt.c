#include "shell.h"

/**
 * prompt - Display prompt
 */
void prompt(void)
{
	PRINTER("$ ");
}
/**
 * print_error - Display error and line counter (exec counter)
 * @input:User Input
 * @counter:execute counter
 * @argv:Program
 * Return: void
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}
/**
 *  _prerror - Custom perror.
 * @argv:argv
 * @counter:Execute counter
 * @cmd:Command
 * Return: Void
 */
void _prerror(char **argv, int counter, char **cmd)
{
	char *er = _itoa(counter);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");
	free(er);
}
