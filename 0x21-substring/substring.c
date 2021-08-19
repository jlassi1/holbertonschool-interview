# include "substring.h"

/**
 * find_substring - function that finds all the possible
 * substrings containing a list of words, within a given string 
 * 
 * @s: is the string to scan
 * @words: is the array of words all substrings must be a concatenation arrangement of
 * @nb_words: is the number of elements in the array words
 * @n: holds the address at which to store the number of elements in the returned array
 * 
 * Return: an allocated array, storing each index in s or NULL if faild
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
int size, word_size, j, i = 0, l;
	int *elements, *found;

	if (!s)
		return (NULL);
	*n = 0, size = strlen(s), word_size = strlen(words[0]);
	found = malloc(nb_words * sizeof(int));
	elements = malloc(size * sizeof(int));
	while (i <= size - nb_words * word_size)
	{
		for (j = 0; j < nb_words; j++)
			found[j] = 0;
		for (j = 0; j < nb_words; j++)
		{
			for (l = 0; l < nb_words; l++)
			{
				if (found[l] == 0 &&
					strncmp(s + i + j * word_size, words[l], word_size) == 0)
				{
					found[l] = 1;
					break;
				}
			}
			if (l == nb_words)
				break;
		}
		if (j == nb_words)
			elements[*(n + 1)] = i;
		i++;
	}
	free(found);
	return (elements);


}
