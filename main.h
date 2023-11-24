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
int process_command(char **argv);
char *which(char *command);
void handle_segmfault(int signo __attribute__((unused)));

/**
 * struct Node - a singly linked list
 * @str: malloc'ed string
 * @next: points to the next node
 */
struct Node
{
	char *str;
	struct Node *next;
};

static struct Node *new_node(char *str) UNUSED;
/**
 * new_node - func that creates a new node for a singly linked list
 * @str: string value to be stored in new node
 * Return: pointer to the new node
 */
static struct Node *new_node(char *str)
{
	struct Node *node = malloc(sizeof(struct Node));

	if (node == NULL)
		return (NULL);
	node->str = str;
	node->next = NULL;
	return (node);
}

static void add_node(struct Node **head, struct Node *node) UNUSED;
/**
 * add_node - add node to the end of a singly linked list
 * @head: pointer to the head of the s..linked list
 * @node: node to be added to the s..linked list
 */
static void add_node(struct Node **head, struct Node *node)
{
	if (*head == NULL)
		*head = node;
	else
	{
		struct Node *current = *head;

		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
}

void add_env_var(struct Node **head, const char *name, const char *value);
void updt_env(struct Node *head);
void print_list(struct Node *head);
void free_list(struct Node *head);
int _env(void);
int _setenv(const char *name, const char *value);
int _unsetenv(const char *name);

/**
 * struct alias_s - structure rep an alias
 * @name: name of the alias
 * @value: vallue of the alias
 * @next: pointer to the next alais in the s..linked list
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;
void _perror(char *err, int count, char *c);
void _perrore(char *err, int count, char *c, char *arg);
void print_all_aliases(alias_t *aliases);
void init_aliases(alias_t **aliases);
int alias_command(char *argv[MAX_ARGS], int num_arg __attribute__((unused)));
void set_alias(alias_t **aliases, char *name, char *value);
void print_alias(alias_t *alias);
void _exec(char **_argum, char *av, int count);
void _execve(char *c, char **p, char **r);
void _perrror(char *err, int count, char *c);
void _print(char *s);
void _pnumber(int n);
int access_check(char **arg, char *cmd, char *err, int c, char **e);

#endif
