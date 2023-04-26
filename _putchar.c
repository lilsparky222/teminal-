#include <unistd.h>

/**
 * _putchar - writes a single character c to stdout
 * @c: the character to be printed to stdout
 *
 * Return: on 1 successful
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
