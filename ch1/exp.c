#include <stdio.h>

int power(int base, int exp);

// unit test
main()
{
	int i;

	for (i = 0; i < 10; i++) {
		printf("%d %d %d\n", i, power(2, i), power(-3, i));
	}
	return 0;
}

// power()
int power(int base, int exp)
{
	int i, p;

	p = 1;

	for (i = 1; i <= exp; i++) {
		p = p * base;
	}
	return p;
}