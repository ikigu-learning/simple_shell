#ifndef MAIN_H
#define MAIN_H

int _strlen(char *str);

char *_strcpy(char *dest, const char *src);

int starts_with(char *str1, char *str2);

char *_strcat(char *str1, char *str2);

/* size_t __printlist(const list_t *h); */

/* void __freelist(list_t *head); */

char *find_path(char *env[]);

char **tokenize_path(char *str);

char **tokenize_command(char *str);

void execute(char *command_tokens[]);

char *find_exe(char *path_tokens[], char *command);

void run_command(char **env, char *buffer);

void free_grid(char **grid);

#endif
