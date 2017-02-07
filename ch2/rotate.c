/*
Exercise 2-8
Write a function rotate(int x, int n)
That returns an integer matching x rotated right by n
*/

#include <stdio.h>

int rotate(int x, int n);
void printbits(int x);

int main()
{
	int x = 0x1d23f4e;
	int n = 5;
	printf("x is:\n");
	printbits(x);
	printf("x rotated by %d bits: \n", n);
	printbits(rotate(x, n));

	return 0;
}

int rotate(int x, int n)
{
	int lsb;		// least significant bit
	unsigned y = x;	// unsigned doesn't arithmetic shift
	int i;

	for (i = 0; i < n; i++) { 
		lsb = y & 1;
		y = (y >> 1) + (lsb << 31);
	}

	return y;
}

void printbits(int x)
{
	int i;
	int n;

	for (i = 1; i <= 32; i++) {
		n = x >> (32 - i);
		printf("%d", n & 1);
	}

	printf("\n");
}