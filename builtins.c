#include "shell.h"
/**
 * exit_bi - Exit with status
 * @cmd: tokens
 * @input: user input
 * @argv: argv
 * @c:execute counter
 * @er: codigo de error anterior
 * Return: Void
 */
void  exit_bi(char **cmd, char *input, char **argv, int c, int er)
{
	int status, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			_prerror(argv, c, cmd);
			break;
		}
		else
		{
			status = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(status);
		}
	}
	return (er);
}


/**
 * change_dir - cd built in
 * @cmd: tokens
 * @er: status of last command
 * Return: 0 on success
 */
int change_dir(char **cmd, __attribute__((unused))int er)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
/**
 * dis_env - display env
 * @cmd:tokens
 * @er:status of last command executed
 * Return:Always 0
 */
int dis_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int er)
{
	size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * display_help - Displaying Help For Builtin
 * @cmd:Parsed Command
 * @er: status of last command executed
 * Return: 0 Succes -1 Fail
 */
int display_help(char **cmd, __attribute__((unused))int er)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}
/**
 * echo_bi - echo built in
 * @er:status of last command executed
 * @cmd: Parsed Command
 * Return: Always 1 or execute echo
 */
int echo_bi(char **cmd, int er)
{
	char *path;
	unsigned int  pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_number(er);
		PRINTER("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINTER("\n");

	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINTER(path);
		PRINTER("\n");
		free(path);

	}
	else
		return (print_echo(cmd));

	return (1);
}
