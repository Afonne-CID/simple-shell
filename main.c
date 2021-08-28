#include "shell.h"

/**
 * * main - Entry point
 *
 * Return: 0;
 */
int main(void)
{
	counter *ptr;

	while (1)
	{
		ptr = malloc(sizeof(ptr));
		ptr->cnt++;
		prompt1();
		locate();
	}
	return (0);
}
