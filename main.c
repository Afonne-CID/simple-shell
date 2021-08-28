#include "shell.h"

/**
 * * main - Entry point
 *
 * Return: 0;
 */
int main(void)
{
	counter *ptr;
	ptr = malloc(sizeof(char *));
	ptr->cnt = 0;

	while (1)
	{
		prompt1();
		locate();
		ptr->cnt++;
	}

	free(ptr);
	return (0);
}
