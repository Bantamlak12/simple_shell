#include "shell.h"

/**
 * execute - executes parsed lines
 * @argv: parsed arguments
 */

void execute(char *argv[], char **parsed)
{
	if (!parsed || !parsed[0])
		return;
	if (fork() == 0)
	{
		if (execve(parsed[0], parsed, environ) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
}

/**
 * split_line - splits line read from getline into tokens
 * @line: a line to be splited
 * Return: tokens
 */

char **split_line(char *line)
{
	char *token;
	char **toks;
	char *str = NULL;
	int i = 0, size = 0;

	str = strdup(line);
	while (*line++)
	{
		size++;
	}
	toks = malloc(sizeof(char *) * size);
	if (toks == NULL)
	{
		free(toks);
		perror("");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, " \n");
	while (token)
	{
		toks[i++] = token;
		token = strtok(NULL, " \n");
	}
	toks[i] = NULL;

	return (toks);
}
