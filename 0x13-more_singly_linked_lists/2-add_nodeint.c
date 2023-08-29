#include "lists.h"

/**
 * Comments For 3rd Task.
 * add_nodeint : This Function Adds a new node at the beginning of a linked list.
 * @head: Declares that pointer to first node in a list.
 * @n:It declares that data to be inserted in that new node.
 *
 * Return: It declares that pointer to the NEW node or NULL if fails.
 * End Of Comments.
 */

listint_t *add_nodeint(listint_t **head, const int n){
	listint_t *new;
	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = *head;
	*head = new;
	return (new);
}
