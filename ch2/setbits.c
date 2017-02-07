/* Exercise 2-6:
 * Write a function setbits(x, p, n, y):
 * returns a modified x such that
 * the n bits of x starting at p
 * are set to the rightmost n bits of y
 */

#include <stdio.h>

int setbits(int x, int p, int n, int y);
int getbits(int x, int n);
void printbits(int x);

int main()
{
	int x = 1231;
	int p = 6;
	int n = 3;
	int y = 351;

	printf("x: ");
	printbits(x);

	printf("y: ");
	printbits(y);

	printf("p: %d\n", p);
	printf("n: %d\n", n);


	int z = setbits(x, p, n, y);
	printf("z: ");
	printbits(z);

 	return 0;
}

int setbits(int x, int p, int n, int y)
{
	int mask = (1 << 31) >> (31 - n);
	mask = mask << (p - n);
	mask = mask + (1 << (p - n)) - 1;
	y = getbits(y, n);
	y = y << (p - n);
	x = x & mask;
	return x + y;
}

// returns an int equal to the rightmost bits of x
int getbits(int x, int n)
{
	int mask = ~(~0 << n);
	return x & mask;
}

// prints the int x in binary (32-bit)
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
