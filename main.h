#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 100
#define MAX_TOKEN_SIZE 64
#define READ_BUFFER_SIZE 1024
#define USE_GETLINE 0
#define USE_STRTOK 0
#define INFO_INIT

void execute_command(char *command);
void parse_input(char *input, char **tokens);
void handle_exit(void);
void handle_env(void);
int betty_check(void);
int _strlen(char *);
int _strcmp(char *, char *);
char *_strcat(char *, char *);
void *_realloc(void *, unsigned int, unsigned int);
char *_memset(char *, char, unsigned int);
void ffree(char **);
char **custom_strtok(char *s, char *del);
int is_delim(char, char *);
int isalphabet(int);
int _atoi(char *);
int hello(void);
extern char **environ;
/**
 * struct information- pseudo-arguments to pass into a function
 * @arg: string generated from getline
 * @path: current command string path
 * @argc: argument counter
 * @fname: program file name
 * @status: return status of the last executed command
 * @readfd: fd from which to read line input
 * @argv: array of strings generated
 */
typedef struct information
{
	char *arg;
	char *path;
	int argc;
	char *fname;
	int status;
	int readfd;
	char **argv;
} info_t;
/**
 * struct inherent- builtin string and related function
 * @t: the builtin command flag
 * @func: the function
 */
typedef struct inherent
{
	char *t;
	int (*func)(info_t *);
} inherent_t;
#endif
