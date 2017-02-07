/* Ex 2-7
 * Write a function invert(x, p, n)
 * that returns a modified x
 * with the n bits that begin at position p inverted.
 */

 #include <stdio.h>

 int invert(int x, int p, int n);
 void printbits(int x);

 int main()
 {
 	int x = 235;
 	int p = 6;
 	int n = 4;
 	int r;

 	printbits(x);

 	r = invert(x, p, n);
 	printbits(r);

 	return 0;
 }

 int invert(int x, int p, int n)
 {
 	// zero out the bits from p to p - n in x:
 	int mask;
 	int x_masked;
 	mask = (~0 << p) + (1 << (p - n)) - 1;
 	x_masked = x & mask;

 	// get those n bits alone with all 0s otherwise:
 	int n_bits;
 	mask = ~mask;
 	n_bits = x & mask;

 	// invert those n_bits, remask, and add to x_masked:
 	n_bits = ~n_bits;
 	n_bits = n_bits & mask;
 	x_masked = x_masked + n_bits;

 	return x_masked;
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