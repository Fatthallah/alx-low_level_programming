#ifndef LISTS_H
#define LISTS_H
#include <stdio.h>
#include <stdlib.h>

typedef struct dlistint_s
{
	int n;
	struct dlistint_s *prev;
	struct dlistint_s *next;
} dlistint_t;

size_t print_dlistint(const dlistint_t *h);
size_t dlistint_len(const dlistint_t *h);
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
void free_dlistint(dlistint_t *head);
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
int sum_dlistint(dlistint_t *head);
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);

#endif 


100-password

en C Pyfo neZ

102-result.py

#!/usr/bin/python3

largest_palindrome = 0

for i in range(100, 1000):
    for j in range(100, 1000):
        product = i * j
        if str(product) == str(product)[::-1] and product > largest_palindrome:
            largest_palindrome = product

# Save the result in the file
with open("102-result", "w") as file:
    file.write(str(largest_palindrome))


103-keygen.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int __attribute__((__unused__)) argc, char *argv[])
{
    char password[7], *codex;
    int len = strlen(argv[1]), i, tmp;

    codex = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";


    tmp = (len ^ 59) & 63;
    password[0] = codex[tmp];

    tmp = 0;
    for (i = 0; i < len; i++)
        tmp += argv[1][i];
    password[1] = codex[(tmp ^ 79) & 63];

    tmp = 1;
    for (i = 0; i < len; i++)
        tmp *= argv[1][i];
    password[2] = codex[(tmp ^ 85) & 63];

    tmp = 0;
    for (i = 0; i < len; i++)
    {
        if (argv[1][i] > tmp)
            tmp = argv[1][i];
    }
    srand(tmp ^ 14);
    password[3] = codex[rand() & 63];

    tmp = 0;
    for (i = 0; i < len; i++)
        tmp += (argv[1][i] * argv[1][i]);
    password[4] = codex[(tmp ^ 239) & 63];

    for (i = 0; i < argv[1][0]; i++)
        tmp = rand();
    password[5] = codex[(tmp ^ 229) & 63];

    password[6] = '\0';

    printf("%s", password);

    return (0);
}

