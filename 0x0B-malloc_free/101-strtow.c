#include <stdlib.h>
#include "main.h"

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
	int flag, c, w;

	flag = 0;
	w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return (w);
}

/**
 * allocate_memory - allocate memory for a string
 * @str: string to allocate memory for
 * @start: starting index of the string
 * @end: ending index of the string
 *
 * Return: pointer to the allocated memory
 */
char *allocate_memory(char *str, int start, int end)
{
	char *tmp;
	int i, len = end - start;

	tmp = (char *)malloc(sizeof(char) * (len + 1));

	if (tmp == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		tmp[i] = str[start + i];
	tmp[len] = '\0';

	return (tmp);
}

/**
 * split_string - split the string into words
 * @str: string to split
 * @matrix: pointer to store the split words
 *
 * Return: void
 */
void split_string(char *str, char **matrix)
{
	int i, k = 0, len = 0, c = 0, start, end;

	while (*(str + len))
		len++;

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				matrix[k] = allocate_memory(str, start, end);

				if (matrix[k] == NULL)
					return;

				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[k] = NULL;
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **matrix;
	int words;

	if (str == NULL || *str == '\0')
		return (NULL);

	words = count_word(str);

	if (words == 0)
		return (NULL);

	matrix = (char **)malloc(sizeof(char *) * (words + 1));

	if (matrix == NULL)
		return (NULL);

	split_string(str, matrix);

	return (matrix);
}
