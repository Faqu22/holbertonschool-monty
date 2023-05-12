#include "monty.h"

/**
 * free_arr - free all the array
 * @array: array to free
 * Return: nothing
 */
void free_arr(char **array)
{
	int i = 0;

	if (array == NULL)
		return;
	for (i = 0; array[i]; i++)
		free(array[i]);
	free(array);
}

/**
 * get_command - take commands from file f
 * @f: file
 * Return: returns the address of the memory with commands
 */

char *get_command(FILE *f)
{
	char *string = NULL, *str = NULL;

	string = malloc(100);
	if (string == NULL)
		return (NULL);
	str = fgets(string, 100, f);
	if (str == NULL)
		free(string);
	return (str);
}
/**
 * split_command - split a command line
 * @string: string whit commands
 * @parameter: string with separator characters
 * Return: nothing
 */
char **split_command(char *string, char *parameter)
{
	char *copy_input = NULL, *token = NULL, **segm = NULL;
	int len = 2;

	copy_input = strdup(string);
	token = strtok(copy_input, parameter);
	if (!token)
	{
		free(copy_input);
		return (NULL);
	}
	segm = (char **)malloc(sizeof(char *) * (len + 1));
	if (segm == NULL)
	{
		free(copy_input);
		return (NULL);
	}
	for (len = 0; len < 2 && token; len++)
	{
		segm[len] = strdup(token);
		token = strtok(NULL, parameter);
	}
	free(copy_input);
	segm[len] = NULL;
	return (segm);
}

/**
 * _nop - do nothing
 * to the next node and removes the top node of the stack
 * @stack: linked list with the stack
 * @line_number: number of line
 * Return: nothing
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * free_stack - free a list.
 * @head: list a free.
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	if (head)
		free_stack(head->next);
	free(head);
}
