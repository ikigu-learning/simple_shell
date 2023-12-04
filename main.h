#ifndef MAIN_H
#define MAIN_H

int _strlen(char *str);
char *_strcpy(char *dest, const char *src);
int starts_with(char *str1, char *str2);
char *_strcat(char *str1, char *str2);
size_t __printlist(const list_t *h);
void __freelist(list_t *head);

/**
 * struct _PATH - a structure of the PATH dirs.
 * @_dir: pointer to pathname
 * @next: pointer to the next structure.
 */
struct _PATH 
{
	char *_dir;
	char struct _PATH *next;
}

/**
 * _path - type definiton of _PATH
 */
typedef struct _PATH _path;

#endif
