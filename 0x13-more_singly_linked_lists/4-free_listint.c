#include "lists.h"

/**
 * Comment of 5th Task.
 * Task Name: Free list.
 * _free_listint : It Frees The Linked List.
 * _@head: The Function listint_t Lists to be freed.
 * End Of Comments.
 */
void free_listint(listint_t *head){
	listint_t *temp;
	while(head){
		temp = head->next;
		free(head);
		head = temp;
	}
}
