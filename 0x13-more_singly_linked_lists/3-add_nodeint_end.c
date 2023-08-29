#include "lists.h"

/**
 * Comments of 4th Task.
 * Task Name : Add node at the end.
 * _add_nodeint_end : This Function Adds a node at the end of The linked list.
 * _@head: Declares that The Pointer to a first element in the list.
 * _@n: Declares that Data to be inserted in a new element.
 *
 * _Return: Thaat declares pointer to the NEW NOde, or NULL if it fail.
 * End Of Comments.
 */

listint_t *add_nodeint_end(listint_t **head, const int n){
	listint_t *new;
	listint_t *temp = *head;
	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL){
		*head = new;
		return (new);
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (new);
}
