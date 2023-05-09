#include "monty.h"

extern char **segm;


void free_arr(char **array)
{
    int i = 0;

	if (array == NULL)
		return;
	for (i = 0; array[i]; i++)
		free(array[i]);
	free(array);
}

char *get_command(FILE *f)
{
	char *string = NULL;

	string = malloc(100);
	if (string == NULL)
		return (NULL);
	string = fgets(string, 100, f);
	return (string);
}

void split_command(char *string, char *parameter)
{
	char *copy_input = NULL, *token = NULL;
	int len = 0;

	copy_input = strdup(string);
	token = strtok(copy_input, parameter);
	for (len = 0; token; len++)
		token = strtok(NULL, parameter);

	segm = (char **)malloc(sizeof(char *) * (len + 1));
	if (segm == NULL)
	{
		return;
	}
	copy_input = strdup(string);
	token = strtok(copy_input, parameter);
	for (len = 0; token; len++)
	{
		segm[len] = strdup(token);
		token = strtok(NULL, parameter);
	}
	segm[len] = NULL;
	return;
}

void _push(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *new = NULL;
	stack_t *temp = *stack;

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
 * free_dlistint - free a list.
 *
 * @head: list a free.
 */
void free_stack(stack_t *head)
{
	stack_t *current = head;
	stack_t *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}