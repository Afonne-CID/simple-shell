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

#define KEEP_CNT 0


/* Global environemnt */
extern char **environ;

/**
 * struct count - struct to keep the number of execution of "hsh".
 * @cnt: member
 */
typedef struct list
{
	int cnt;
	struct list *next;
} list_t;

char *buf_size(char *next, char *buffer);
void fetch_builtin(char *args);
char *_tostring(int num);
void err_msg(char **args);
int hsh_exit(void);
void hsh_cd(char **args);
int hsh_help(void);

int _putchar(char c);
char **_getenv(const char *var);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

int _strcmp(char *s1, char *s2);
int hsh_exec(char *token, char **args);
int locate(void);
void executor(char *token);
char *_strncpy(char *dest, char *src, int n);
void free_mem(char **str);
char **_tokenizer(char *str, char *delim);
void prompt1(void);
void prompt2(void);
char *retrieve_input(void);
char *_strcpy(char *dest, char *src);
int _strlen(const char *str);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
int _strncmp(const char *s1, const char *s2, size_t n);

#endif
