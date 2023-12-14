#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024
#include <stddef.h>
#include <errno.h>
#include <unistd.h>

extern char **environ;

int _isin(char *s, char c);

void _notfound(char *argv, char *com);

int _strlen(char *str);

char *_strcpy(char *dest, const char *src);

int starts_with(char *str1, char *str2);

char *_strcat(char *str1, char *str2);

void replace_newline_char_with_null(char *str);

char *find_path(char *env[]);

char **tokenize_path(char *str);

char **tokenize_command(char *str);

void execute_command(char *command_tokens[]);

char *find_exe(char *path_tokens[], char *command);

void parse_command(char *buffer, char **path_tokens);

void free_grid(char **grid);

char *read_teractive_cmd(char *path[], char *buffer);

char *read_xteractive_cmd(char *path[], char *buffer);

void _printenv(char *env[]);

int _putchar(char c);

int extend_buffer(size_t *i, char **buffer, size_t *buffer_size);

#endif
