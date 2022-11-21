#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>


extern char **environ;


void handle_signal(int sig);
void _prompt(void);
char *_getline(void);
char **split_line(char *line);
void execute(char *argv[], char **parsed);

#endif /* _SHELL_H_ */
