#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

#include <stdio.h>
#include <string.h>

/* Global environemnt */
extern char **environ;

/* inbuilt structure data type */
struct stat stats;

/**
 * struct list_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/**
 * struct builtin_s - A new struct type defining builtin commands.
 * @name: The name of the builtin command.
 * @f: A function pointer to the builtin command's function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

char *strip(char *path);
int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);
char **_strtok(char *line, char *delim);
char **_copyenv(void);
void free_env(void);
char *_getenv(const char *var);
char *fill_path_dir(char *path);
list_t *get_path_dir(char *path);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

void locate(void);
void executor(char *token);
char *_strncpy(char *dest, char *src, int n);
void free_mem(char **str);
char **_tokenizer2(char *str);
char **_tokenizer(char *str, char *delim);
void prompt1(void);
char *retrieve_input(void);
char *_strcpy(char *dest, char *src);
int _strlen(const char *str);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
int _strncmp(const char *s1, const char *s2, size_t n);

char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);

char **_strtok(char *line, char *delim);
int count_tokens(char *str, char *delim);
int token_len(char *str, char *delim);

list_t *add_node_end(list_t **head, char *dir);
void free_list(list_t *head);

char **_copyenv(void);
void free_env(void);

char *get_location(char *command);
list_t *get_path_dir(char *path);
void free_list(list_t *head);

#endif
