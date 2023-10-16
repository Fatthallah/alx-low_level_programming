#include <stdio.h>

int add(int a, int b) {
	int r;
	r = a + b;
	return (r);
}

int sub(int a, int b) {
        int r;
        r = a - b;
        return (r);
}

int mul(int a, int b) {
        int r;
        r = a * b;
        return (r);
}

int div(int a, int b) {
	if (b == 0)
	{
		printf("Error");
		return (0);
	}
        int r;
        r = a / b;
        return (r);
}

int mod(int a, int b) {
	if (b == 0)
	{
		printf("Error");
		return (0);
	}
        int r;
        r = a % b;
        return (r);
}
