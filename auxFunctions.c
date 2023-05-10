#include "monty.h"

extern char **segm;

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
 * split_buff - split a command line
 * @string: string whit commands 
 * @parameter: string with separator characters
 * Return: nothing
 */
void split_command(char *string, char *parameter)
{
	char *copy_input = NULL, *token = NULL;
	int len = 2;

	copy_input = strdup(string);
	token = strtok(copy_input, parameter);
	if (!token)
		{
			free(copy_input);
			segm = NULL;
			return;
		}
	segm = (char **)malloc(sizeof(char *) * (len + 1));
	if (segm == NULL)
	{
		free(copy_input);
		return;
	}
	for (len = 0; len < 2 && token; len++)
	{
		segm[len] = strdup(token);
		token = strtok(NULL, parameter);
	}
	free(copy_input);
	segm[len] = NULL;
	return;
}

/**
 * _push - add a node to the top of the stack
 * @stack: linked list with the stack
 * @line_number: number of line
 * Return: nothing
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	stack_t *temp = *stack;
	int i = 0;

	if(!(segm[1]))
		{
			free_stack(*stack);
			free_arr(segm);
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	for(; segm[1][i] != '\0'; i++)
		if(strchr("-0123456789", segm[1][i]) == NULL)
		{
			free_stack(*stack);
			free_arr(segm);
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return;
	new->n = atoi(segm[1]);
	if (temp)
	{
		temp->prev = new;
		new->next = temp;
		(*stack) = new;
	}
	else
	{
		*stack = new;
		new->next = NULL;
	}
	new->prev = NULL;
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