#ifndef _LIB_H
#define _LIB_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>


#define BUFFER_SIZE 1024
#define MX_PTH_LNTH 1024
extern char **environ;

void print_env(void);
void execute_command(char *buffer, char *av[], int cnt);
char *f_ex_path(const char *command, char *av[], int cnt);
size_t _strcspn(const char *str, const char *r);
int _strcmp(const char *str1, const char *str2);
char *_strdup(const char *str);
int isSubstring(const char *str, const char *sub);
char *get_pth(const char *pth);
int _chpath(const char *command);
int  _strlen(const char *str);
int print_prompt_count(int n);
int _putchar(char c);
int handle_errors(char **command, char *program[], int prompt_count, int error_num);
#endif
