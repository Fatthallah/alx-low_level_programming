#include "lists.h"

/**
 * Comments of 2nd Task.
 * listint_len : This Function Returns the number of elements in a linked lists.
 * @h: linked list to be traversed of type listint_t.
 *
 * Return: It declares that it will be number of nodes.
 * End Of Comments of 2nd Task.
 */
size_t listint_len(const listint_t *h){
	size_t num = 0;
	while (h){
		num++;
		h = h->next;
	}
	return (num);
}
