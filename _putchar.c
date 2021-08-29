#include "shell.h"

/**
 * _putchar - prints a single anscii character to console
 * @c: the character
 *
 * Return: int
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
