// Use the fact that x &= (x - 1) deletes the
// rightmost 1 bit in x to write a faster bitcount()

#include <stdio.h>

int bitcount2(unsigned x);
int bitcount(unsigned x);

int main()
{
	int x = 3456;
	int y = 37;
	int z = 108973;

	printf("1: %d, 2: %d\n", bitcount(x), bitcount2(x));
	printf("1: %d, 2: %d\n", bitcount(y), bitcount2(y));
	printf("1: %d, 2: %d\n", bitcount(z), bitcount2(z));

	return 0;
}

int bitcount2(unsigned x)
{
	int n = 0;
	while (x != 0) {
		x &= (x - 1);
		n++;
	}

	return n;
}

int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1) {
		if (x & 01) {
			b++;
		}
	}

	return b;
}