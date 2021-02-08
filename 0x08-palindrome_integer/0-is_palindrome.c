#include "palindrome.h"
/**
 *is_palindrome-checks whether or not a given unsigned integer is a palindrome.
 *
 *@n: the given integer to checks it
 *
 *
 *Return: 1 if palindrome or 0 if not
 */
int is_palindrome(unsigned long n)
{
int reversedN = 0, remainder, originalN;

	originalN = n;


	while (n != 0)
	{
		remainder = n % 10;
		reversedN = reversedN * 10 + remainder;
		n /= 10;
	}

	if (originalN == reversedN)
		return (1);

	return (0);
}

