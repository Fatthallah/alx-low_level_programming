#include "lists.h"

/**
 * Comments of 6th Task.
 * Task Name: Free.
 * _free_listint2 :It declares that Frees The linked list.
 * _@head: It Declares that Pointer to a listint_t list to be freeed.
 * End Of Comments.
 */

void free_listint2(listint_t **head){
	listint_t *temp;
	if (head == NULL)
		return;
	while (*head){
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	*head = NULL;
}
