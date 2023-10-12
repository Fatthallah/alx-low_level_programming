#include "lists.h"

/**
 * dlistint_len - this fun
 * @h: refer to
 * Return: element num
 */
 
size_t dlistint_len(const dlistint_t *h)
{
    size_t nodes = 0;

    while (h)
    {
        nodes++;
        h = h->next;
    }
    return (nodes);
}

