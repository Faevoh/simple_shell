#ifndef _MAIN_H_
#define _MAIN_H_

#define MAX_ARGS 100

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int access(const char *pathname, int mode);
int chdir(const char *path);
int execve(const char *pathname, char *const argv[], char *const envp[]);
void exit(int status);
pid_t fork(void);
ssize_t getline(char **lineptr, size_t *l, FILE *stream);
pid_t getpid(void);
pid_t wait(int *status);
void cmdline(char *cmmand, char **args);
char *cmdStrtok(char *str, char const *delim);
char *getenv(const char *name);
char *strtok(char *str, const char *delim);
char *cmdPath(char *cmmand);
void cmdEnv(void);
void cmd_cd(char *path);

#endif
