#include "lists.h"

/**
 * Commenth of 8th Task.
 * Task Name: Get node at index.
 * _get_noodeeint_at_index: This Function Returns a noode to a certain index in a Linked List.
 * _@head:This Function do >>  Fiirst noode in a linked list.
 * _@index: This Fun. >>  Inndex of a Moode to be returned.
 *
 * _Return:This Fun. >>  maake Pointers to a Noode we are Searching for, or it but null.
 * End Of Comments.
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index){
	unsigned int i = 0;
	listint_t *temp = head;
	while (temp && i < index){
		temp = temp->next;
		i++;
	}
	return (temp ? temp : NULL);
}
