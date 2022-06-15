#include "palindrome.h"

/**
 * is_palindrome - checks if a string is a palindrome
 *
 * @str: string to check
 * @len: length of string
 *
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0;
	unsigned long temp = n;

	while (n > 0)
	{
		rev = rev * 10 + n % 10;
		n /= 10;
	}

	if (rev == temp)
		return (1);

	return (0);
}
