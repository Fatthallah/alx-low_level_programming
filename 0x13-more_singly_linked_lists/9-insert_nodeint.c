#include "lists.h"

/**
 * Comments
 * Task Name:  Insert.
 * _insert_nodeint_at_index :It Declares >> Insserts a NEW noodee in The linked list at The REQ. position.
 * _@head: IT Declareds >> Pointeer to a Fiirst noodee in a_List.
 * _@idx: IT Declares >>>>> Innndex where the a Nodee is addeed.
 * _@n: IT Declares >>>>> DDData to be inserted in a NEW nodee.
 *
 * _Return:IT Declares >>>>> #Ppointer to the new nodee Or nuull.
 *End of Comment
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n){
	unsigned int i;
	listint_t *new;
	listint_t *temp = *head;
	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (idx == 0){
		new->next = *head;
		*head = new;
		return (new);
	}
	for (i = 0; temp && i < idx; i++){
		if (i == idx - 1){
			new->next = temp->next;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}
	return (NULL);
}
