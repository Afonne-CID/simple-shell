#include "shell.h"

/**
 * free_mem - free memory of multi-dimensional array
 * @str: the array of arrays to free
 */
void free_mem(char **str)
{
	int i;

	i = 0;
	while (!(*(str + i)))
	{
		free(str[i]);
		i++;
	}
}

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated.
 * @old_size: The size in bytes of the allocated space for ptr.
 * @new_size: The size in bytes for the new memory block.
 *
 * Return: If new_size == old_size - ptr.
 *         If new_size == 0 and ptr is not NULL - NULL.
 *         Otherwise - a pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *mem;
	char *ptr_copy, *filler;
	unsigned int index;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		mem = malloc(new_size);

		if (mem == NULL)
			return (NULL);

		return (mem);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr_copy = ptr;
	mem = malloc(sizeof(*ptr_copy) * new_size);

	if (mem == NULL)
	{
		free(ptr);
		return (NULL);
	}

	filler = mem;

	for (index = 0; index < old_size && index < new_size; index++)
		filler[index] = *ptr_copy++;

	free(ptr);
	return (mem);
}

/**
 * buf_size - resizes pointer to array of chars
 * @next: parameter to resize
 * @buffer: parameter to realloc with
 *
 * Return: pointer to new malloc'd or realloc'd size
 */
char *buf_size(char *next, char *buffer)
{
	if (!next)
	{
		next = malloc(sizeof(char *) * _strlen(buffer) + 1);
		if (!next)
		{
			free(buffer);
			return (NULL);
		}
	}
	else
	{
		next = _realloc(next, _strlen(next), _strlen(next) + _strlen(buffer) + 1);
		if (!next)
		{
			free(buffer);
			free(next);
			return (NULL);
		}
	}
	return (next);
}
