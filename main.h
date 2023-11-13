#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 100
#define MAX_TOKEN_SIZE 64

void printr(const char *string);
void execute_command(char *command);
void parse_input(char *input, char **tokens);
void handle_exit(void);
void handle_env(void);
#endif
