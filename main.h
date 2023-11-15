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

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 100
#define MAX_TOKEN_SIZE 64
#define READ_BUFFER_SIZE 1024
#define USE_GETLINE 0
#define USE_STRTOK 0
#define INFO_INIT

void printHelloWorld(int num);
void printr(const char *string);
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

typedef struct information
{
	char *arg;
	char *path;
	int argc;
	char *fname;
	int status;
	int readfd;
} info_t;
#endif
