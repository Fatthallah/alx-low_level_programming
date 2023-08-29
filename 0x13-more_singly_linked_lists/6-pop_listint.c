#include "lists.h"

/**
 * Comment For 7th Task.
 * Task Name: Pop.
 * _pop_listint - This function Deleetes a head Noode of a linked list.
 * _@head: It declares that Pointer to a 1st Elemment in a Linked list.
 *
 * _Return: This Functionreturn the data inside a Elements that were deleted.
 * _or (ZERO) if List is emptey.
 * End Of Comments.
 */

int pop_listint(listint_t **head){
	listint_t *temp;
	int num;
	if (!head || !*head)
		return (0);
	num = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;
	return (num);
}
