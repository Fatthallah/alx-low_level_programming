#include "lists.h"

/**
 * Comments.
 * Task Name: Sum list.
 * _sum_listint :It Declares > Calculates the #SUM of all data in the listint_t list.
 * _@head: What it does >> Fiirst noode in a Linked List.
 *
 * _Return: The Sum.
 */

int sum_listint(listint_t *head){
	int sum = 0;
	listint_t *temp = head;
	while (temp){
		sum += temp->n;
		temp = temp->next;
	}
	return (sum);
}
