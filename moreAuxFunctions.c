#include "monty.h"

/**
 * print_dlistint - print all the elements of list.
 *
 * @h: an list.
 * Return: the number of nodes
 */

void _pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	while ((*stack) != NULL)
	{
		if ((*stack)->n)
			printf("%i", (*stack)->n);
		else
			printf("%i", 0);
		printf("\n");
		(*stack) = (*stack)->next;
	}
}