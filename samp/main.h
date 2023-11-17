#ifndef _MAIN_H_
#define _MAIN_H_

#define MAX_ARGS 100
#define MAX_LINE_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;

int access(const char *pathname, int mode);
int chdir(const char *path);
int execve(const char *pathname, char *const argv[], char *const envp[]);
void exit(int status);
pid_t fork(void);
ssize_t _getLine(char **lineptr, size_t *l, FILE *stream);
pid_t getpid(void);
pid_t wait(int *status);
void cmdline(char *cmmand, char **args);
char *getenv(const char *name);
char *strtok(char *str, const char *delim);
char *cmdPath(char *cmmand);
void cmdEnv(void);
void _exec(char *cmmand, char *args[]);
size_t _strlen(const char *s);

#endif