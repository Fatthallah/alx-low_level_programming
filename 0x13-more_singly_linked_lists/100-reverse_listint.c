#include "lists.h"

/**
 * Comments.
 * Task Name :: Reverse list.
 * _reverse_listint : IT INDICATES >> RReverses THE Linkeed LIst.
 * _@head:IT INDICATES >> THe Pointer to a 1st NooDde in a LIist.
 *
 * _Return:IT INDICATES >> the Pointer to a 1st Noodee in the NEW list.
 * END.
 */
listint_t *reverse_listint(listint_t **head){
	listint_t *prev = NULL;
	listint_t *next = NULL;
	while (*head){
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}
	*head = prev;
	return (*head);
}

