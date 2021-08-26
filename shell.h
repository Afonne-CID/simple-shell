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

char **_getenv(const char *var);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

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
