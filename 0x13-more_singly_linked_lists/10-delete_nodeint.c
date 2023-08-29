#include "lists.h"

/**
 * Comments.
 * Task Name : Delete at index.
 * _delete_nodeint_at_index :: IT Declares that >> Deletees a noodee in The Linked List at a #CEertain_Index.
 * _@head: IT Declares that >> PPointer TO a 1st Eleement in a List.
 * _@index: IT Declares that >> IIndexx of a Nodeee to BE Deleeted.
 *
 * _Return: return  1 (IF Successed) or -1 (IF Failed).
 * End.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index){
	listint_t *temp = *head;
	listint_t *current = NULL;
	unsigned int i = 0;
	if (*head == NULL)
		return (-1);
	if (index == 0){
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	while (i < index - 1){
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		i++;
	}
	current = temp->next;
	temp->next = current->next;
	free(current);
	return (1);
}
