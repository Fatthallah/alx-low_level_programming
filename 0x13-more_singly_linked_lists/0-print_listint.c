#include "lists.h"

/**
 * Comments For 1st Task.
 * _Task_Name : (Print list)
 * _print_listint: It Prints ALL of The Linked List's Elements Given.
 * _@p: It Declare that Linked List to be printed of type listint_t.
 *
 * _Return: What it returns is #Number_of_Nodes.
 * _End Of Comments.
 */

size_t print_listint(const listint_t *p){
	size_t num = 0;
	while(p){
		printf ("%d\n", p->n);
		num++;
		p = p->next;
	}
	return(num);
}
