#include "monty.h"
/**
 * _strdup - duplicates a string
 * @str: is the string
 *
 * Return: a the duplicated string
 */
char *_strdup(char *str)
{
	char *dup = NULL, *dup_offset;
	int len;

	if (str == NULL)
		return (NULL);

	len = strlen(str);

	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	dup_offset = dup;

	while (*str)
	{
		*dup_offset = *str;
		dup_offset++;
		str++;
	}
	*dup_offset = '\0';
	return (dup);
 }
