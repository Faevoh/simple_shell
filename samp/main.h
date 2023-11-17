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
char *_getenv(const char *name, char **envp);
char *strtok(char *str, const char *delim);
char *cmdPath(char *cmmand);
void cmdEnv(void);
void _exec(char *cmmand, char *args[]);
size_t _strlen(const char *s);
void cmdline(char *cmmand, char *args[]);
char *_strsep(char **stringp, const char *delim);
char *_strchr(const char *s, int c);
size_t _strcspn(const char *s1, const char *s2);
size_t _strlen(const char *s);
char *_strdup(const char *s);
char *_strcpy(char *dst, const char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcat(char *dst, const char *src);

#endif
