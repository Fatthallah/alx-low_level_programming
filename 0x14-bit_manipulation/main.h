#ifndef MAIN_H
#define MAIN_H

/* Put_Char */
int _putchar(char c);
/* 0. 0 */
unsigned int binary_to_uint(const char *b);
/* 1. 1 */
void print_binary(unsigned long int n);
/* 2. 10 */
int get_bit(unsigned long int n, unsigned int index);
/* 3. 11 */
int set_bit(unsigned long int *n, unsigned int index);
/* 4. 100 */
int clear_bit(unsigned long int *n, unsigned int index);
/* 5. 101 */
unsigned int flip_bits(unsigned long int n, unsigned long int m);
/* 6. Endianness */
int get_endianness(void);

#endif
