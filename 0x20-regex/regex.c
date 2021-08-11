# include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: is the string to scan
 * @pattern: is the regular expression
 *
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */
int regex_match(char const *str, char const *pattern)
{
if (!str || !pattern)
return (0);
if (*str == '\0' && *pattern == '\0')
return (1);
if (*str == *pattern || (*pattern == '.' && *(pattern + 1) != '*'))
return (regex_match(++str, ++pattern));
if (*str != *pattern && (*pattern != '.' && *(pattern + 1) == '*'))
		return (regex_match(str, pattern + 2));
if (*pattern == '.' && *(pattern + 1) == '*')
{
if (!pattern[2])
return (1);
return (regex_match(str, pattern + 2) || regex_match(str + 1, pattern));
}
if (*pattern == '*')
{
if (*(pattern - 1) == *str)
return (regex_match(str + 1, pattern));
return (regex_match(str, pattern + 1));
}
return (0);
}
