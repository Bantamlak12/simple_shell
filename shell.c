#include "shell.h"

/**
 * _getline - reads line from standard input
 * Return: the buffer
 */
char *_getline(void)
{
	char *buffer = NULL;
	size_t n;

	if (getline(&buffer, &n, stdin) == -1)
	{
		free(buffer);
		exit(EXIT_FAILURE);
	}

	return (buffer);
}

/**
 * _isatty - checks if the input is to a terminal
 *
 */
void _prompt(void)
{
	char *prompt = "($) ";

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, 4);
}

/**
 * handle_signal - handle the signal for 'ctrl + C' and interrupt the process
 * @sig: number of the signal SIGINT(=2)
 */

void handle_sigint(int sig)
{
	char *prompt = "\n($) ";
	if(sig == SIGINT)
		write(STDOUT_FILENO, prompt, 6);
}

/**
 * main - Entry point
 *
 * Return: Always 0.
 */

int main(__attribute__((unused))int argc, __attribute__((unused))char *argv[])
{
	char *line;
	char **parsed;

	signal(SIGINT, handle_sigint);
	while (isatty(STDIN_FILENO))
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			_prompt();
		}
		line = _getline();
		parsed = split_line(line);
		execute(argv, parsed);

		free(line);
		free(parsed);
	}

	exit(EXIT_SUCCESS);
}
