#ifndef _SUBSTRING_
#define _SUBSTRING_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
int cmp_values(const void *a, const void *b);
bool check_words(int *aux_indx, int wordlen, int idx_len);
int *search_word(char const *s, char const **words, int nb_words);

#endif /* _SUBSTRING_ */
