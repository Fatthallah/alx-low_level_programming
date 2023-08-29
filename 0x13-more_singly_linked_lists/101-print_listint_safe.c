#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

size_t looped_listint_len(const listint_t *head){
	const listint_t *XX, *YY;
	size_t nodes = 1;
	if (head == NULL || head->next == NULL)
		return (0);
	XX = head->next;
	YY = (head->next)->next;
	while (YY){
		if (XX == YY){
			XX = head;
			while (XX != YY){
				nodes++;
				XX = XX->next;
				YY = YY->next;
			}
			XX = XX->next;
			while (XX != YY){
				nodes++;
				XX = XX->next;
			}
			return (nodes);
		}
		XX = XX->next;
		YY = (YY->next)->next;
	}
	return (0);
}
size_t print_listint_safe(const listint_t *head){
	size_t nodes, index = 0;
	nodes = looped_listint_len(head);
	if (nodes == 0){
		for (; head != NULL; nodes++){
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (index = 0; index < nodes; index++){
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (nodes);
}

