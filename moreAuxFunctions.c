#include "monty.h"

/**
 * print_dlistint - print all the elements of list.
 *
 * @h: an list.
 * Return: the number of nodes
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