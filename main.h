#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int access(const char *pathname, int mode);
int chdir(const char *path);
int execve(const char *pathname, char *const _Nullable argv[], char *const _Nullable envp[]);
[[noreturn]] void exit(int status);
pid_t fork(void);
char *getcwd(char buf[.size], size_t size);
ssize_t getline(char **restrict lineptr, size_t *restrict n, FILE *restrict stream);
pid_t getpid(void);
pid_t wait(int *_Nullable wstatus);

#endif
