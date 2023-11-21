#ifndef _MAIN_H_
#define _MAIN_H_

/* Macros */
#define MAX_ARGS 100
#define MAX_LINE_SIZE 1024
#define UNUSED __attribute__((unused))

extern int ex_code;
extern char **environ UNUSED;

/* Headers */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>
#include <signal.h>

/* Prototypes */
extern char **environ;
int access(const char *pathname, int mode);
int chdir(const char *path);
int execve(const char *pathname, char *const argv[], char *const envp[]);
void exit(int status);
pid_t fork(void);
ssize_t _getLine(char **lineptr, size_t *l, FILE *stream);
pid_t getpid(void);
pid_t wait(int *status);
char *_getenv(const char *name);
void _exec(char *cmmand, char *args[]);
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
void cmd_cd(char *path);
int _strcmp(const char *s1, const char *s2);
int _strncpy(char *dest, char *src, int size);
void *_realloc(void *ptr, size_t size);
void *_memcpy(void *dest, void *src, size_t n);
void remove_trailing_and_leading_spaces(char *str);
void tokenize(char *command, char *argv[MAX_ARGS]);
int num_args(char *argv[]);
int _atoi(const char *str);
int _1exit(char *status __attribute__((unused)), int c, char *a, char **ag);
void _perror(char *err, int count, char *c);
int process_command(char **argv);
void _perrore(char *err, int count, char *c, char *arg);
char *which(char *command);
void print_all_aliases(alias_t *aliases);
void handle_segmfault(int signo __attribute__((unused)));

void add_env_var(struct Node **head, const char *name, const char *value);
void updt_env(struct Node *head);

#endif
