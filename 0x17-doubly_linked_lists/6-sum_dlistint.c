#include "lists.h"

/**
 * sum_dlistint - fun
 * @head: head
 * Return: yyyyyyyyy
 */
 
int sum_dlistint(dlistint_t *head)
{
	int x = 0;
	while (head)
	{
		x += head->n;
		head = head->next;
	}
	return (x);
}

