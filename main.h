#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024

extern char **environ;

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

void read_interactive_command(char *path_tokens[], char *buffer);

void read_non_interactive_command(char *path_tokens[], char *buffer);

#endif
