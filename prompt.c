#include "shell.h"

/**
 * prompt1 - prints prompt ($ );
 */
void prompt1(void)
{
	write(1, "$", 1);
	write(1, " ", 1);
}

/**
 * prompt2 - prints promot (> ) for mutli line
 */
void prompt2(void)
{
	_putchar('>');
	_putchar(32);
}
