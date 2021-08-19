# include "substring.h"
/**
 * find_substring - Function that search_word words in string
 * @s: is the string to scan
 * @words:  is the array of words all substrings
 * @nb_words: is the number of elements in the array words
 * @n: the address at which to store the number of elements in the returned array
 * Return: array with index for every word or NULL
 *
 **/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *idx, *aux_idx, wordlen, j, diff, s_len, tmp;
    bool  f_idx;

	*n = 0;
	wordlen = (int)strlen(words[0]);
	s_len = (int)strlen(s);
	for (j = 0; j < s_len; j++)
	{
		aux_idx = search_word(s, words, nb_words);
		if (!aux_idx)
			break;
		qsort(aux_idx, nb_words, sizeof(int), cmp_values);
		f_idx = check_words(aux_idx, wordlen, nb_words);
		tmp = aux_idx[nb_words - 1];
		free(aux_idx);
		if (f_idx)
		{
			diff = s_len - tmp;
			if (*n == 0 || diff != idx[*n - 1])
			{
				if (*n == 0)
				{
					idx = malloc((sizeof(int)));
					if (!idx)
						return (NULL);
				}
				else
					idx = realloc(idx, sizeof(int) * (*n + 1));
				idx[*n] = diff;
				*n += 1;
			}
		}
		s++;
	}
	if (*n == 0)
		return (NULL);
	return (idx);
}
/**
 * check_words - Function that chek if all words are continous
 * @aux_idx: array with index for ever word
 * @wordlen: word size
 * @idx_len: aux_idx size
 * Return: index firt word or zero
 **/
bool check_words(int *aux_idx, int wordlen, int idx_len)
{
	int i;

	for (i = 0; i < idx_len - 1; i++)
	{
		if (aux_idx[i + 1] - aux_idx[i] != wordlen)
			return (false);
	}
	return (true);
}
/**
 * search_word - Function that search words in string
 * @s: string base
 * @words: array of words to search in the string
 * @nb_words: number of words
 * Return: array with size of substring for every word, otherwise NULL
 **/
int *search_word(char const *s, char const **words, int nb_words)
{
	int *aux_idx, i, j;
	char *aux;
	int len;

	aux_idx = malloc((sizeof(int) * nb_words));
	if (!aux_idx)
		return (NULL);
	for (i = 0; i < nb_words; i++)
	{
		aux = strstr(s, words[i]);
		if (!aux)
		{
			free(aux_idx);
			return (NULL);
		}
		len = (int)strlen(aux);
		for (j = 0; j < i; j++)
		{
			if (len == aux_idx[j])
			{
				aux = strstr(s + (int)strlen(s) - len + 1, words[i]);
				if (!aux)
				{
					free(aux_idx);
					return (NULL);
				}
				len = (int)strlen(aux);
				aux_idx[i] = len;
				continue;
			}
		}
		aux_idx[i] = len;
	}
	return (aux_idx);
}

/**
 * cmp_values - Function that compare two values
 * @a: first value
 * @b: second value
 * Return: substraction
 **/
int cmp_values(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
