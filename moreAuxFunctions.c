#include "monty.h"

/**
 * _pall - print all the stack
 * @stack: linked list with the stack
 * @line_number: number of line
 * Return: nothing
 */

void _pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		if (temp->n)
			printf("%i", temp->n);
		else
			printf("%i", 0);
		printf("\n");
		temp = temp->next;
	}


}

/**
 * _pint - print the top of the stack
 * @stack: linked list with the stack
 * @line_number: number of line
 * Return: nothing
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - delete the top of the stack
 * @stack: linked list with the stack
 * @line_number: number of line
 * Return: nothing
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;

	if ((*stack)->next != NULL)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(temp);
}

/**
 * _add - adds the value of the top node of the stack
 * to the next node and removes the top node of the stack
 * @stack: linked list with the stack
 * @line_number: number of line
 * Return: nothing
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int i = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	i = temp->n;
	*stack = (*stack)->next;
	free(temp);
	(*stack)->prev = NULL;
	(*stack)->n = (*stack)->n + i;
}

/**
 * _swap - Exchange the values between the top node and the next one
 * @stack: linked list with the stack
 * @line_number: number of line
 * Return: nothing
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = n;
}
