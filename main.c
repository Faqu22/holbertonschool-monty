#include "monty.h"

char **segm = NULL;

/**
 * main - a simple SHELL
 * @argc: size of argv
 * @argv: array with argument
 * Return: 0 all good, 1 an error occurred
 */

int main(int argc, char **argv)
{
	instruction_t function[] = {{"push", _push},
		{"pall", _pall}, {"pint", _pint}, {"pop", _pop},
		{"swap", _swap}, {"add", _add}, {"nop", _nop}, {NULL, NULL}};
	stack_t *list = NULL;
	char *command = NULL;
	int i = 0;
	unsigned int line_number = 0;
	FILE *file;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	while (1)
	{
		line_number++;
		command = get_command(file);
		if (command == NULL)
			break;
		segm = split_command(command, " \n\t");
		free(command);
		if (segm == NULL)
			continue;
		for (i = 0; function[i].opcode != NULL; i++)
			if (strcmp(function[i].opcode, segm[0]) == 0)
			{
				function[i].f(&list, line_number);
				break;
			}
		if (function[i].opcode == NULL)
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", line_number, segm[0]);
			exit(EXIT_FAILURE);
		}
		if (segm != NULL)
			free_arr(segm);
	}
	fclose(file);
	free_stack(list);
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

	if (!segm[1])
	{
		free_stack(*stack);
		free_arr(segm);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (; segm[1][i] != '\0'; i++)
		if (strchr("-0123456789", segm[1][i]) == NULL)
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
