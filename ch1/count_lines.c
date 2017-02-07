#include <stdio.h>

/*
main()
{
	int c;
	int nl;

	nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			++nl;
		}
	}
	printf("%d\n", nl);
}
*/

// Ex 1.8

main()
{
	int c;
	int white_space;

	white_space = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n' || c == ' ' || c == '\t') {
			++white_space;
		}
	}
	printf("%d\n", white_space);
}


