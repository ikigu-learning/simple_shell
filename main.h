#ifndef MAIN_H
#define MAIN_H

int _strlen(char *str);

char *_strcpy(char *dest, const char *src);

int starts_with(char *str1, char *str2);

char *_strcat(char *str1, char *str2);

size_t __printlist(const list_t *h);

void __freelist(list_t *head);

char *find_path(char *env[]);

char **tokenize_path(char *str);

/**
 * struct path - a structure of the PATH dirs.
 * @_dir: pointer to pathname
 * @next: pointer to the next structure.
 */

typedef struct path
{
	char *_dir;

	struct path *next;
} path;

/**
 * struct list_t - a linked list
 * @str: a string
 * @next: a pointer to the next node
 * @len: length of str
*/

typedef struct list_t
{
	char *str;

	struct list_t *next;

	int len;
} list_t;

#endif
