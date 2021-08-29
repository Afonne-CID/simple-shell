#include "shell.h"

/**
 * * main - Entry point
 *
 * Return: 0;
 */
int main(void)
{
	int cnt = 0;

	while (1)
	{
		prompt1();
		locate();
		cnt++;
	}
	return (0);
}
