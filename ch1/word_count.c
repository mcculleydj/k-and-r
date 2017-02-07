/*
main()
{
	int c;  // current char
	int nl; // new line accum
	int nw; // new word accum
	int nc; // new char accum
	int state; // state variable

	state = OUT;

	nl = nw = nc = 0;

	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
		} else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("\nnc: %d, nl: %d, nw: %d\n", nc, nl, nw);
}
*/

// Ex 1-12

#include <stdio.h>

#define IN  1 // inside a word
#define OUT 0 // outside a word

main()
{
	int c;  // current char
	int state;

	state = OUT;

	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\n' && c != '\t') {
			putchar(c);
			state = IN;
		} else {
			if (state == IN) {
				putchar('\n');
				state = OUT;
			}
		}
	}

	if (state == IN) {
		putchar('\n');
	}
}