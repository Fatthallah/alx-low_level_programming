#include <stdlib.h>
#include "../search_algos.h"
void free_list(listint_t *list)
{
	listint_t *node;
	if (list)
	{
		node = list->next;
		free(list);
		free_list(node);
	}
}
