#include "shell.h"

/**
 * handle_builtin - gets the function to execute
 * @cmd: tokens
 * @st: status of last execute
 * Return: 0 if executed , -1 if not
 */

int handle_builtin(char **cmd, int st)
{
	 bul_t bil[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bi},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_strcmp(cmd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->fun(cmd, st));
		}
		i++;
	}
	return (-1);
}
/**
 * check_cmd - Excute cmd
 * @cmd:tokens
 * @input: User Input
 * @c:time case of comand not found
 * @argv:Program Name
 * Return: 1 if cmd null, -1 wrong cmd or 0 cmd executed
 */
int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}

/**
 * signal_to_handel - Handle ^C
 * @sig:signal
 * Return: Void
 */
void signal_to_handel(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
