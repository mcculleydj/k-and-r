#include <stdio.h>

// copy input to output
/*
main()
{
    int c;

	// Ex 1.7
	printf("Value of EOF: %d\n", EOF);

	c = getchar();
	while (c != EOF) {

		// Ex 1.6
		printf("Value of c != EOF: %d\n", c != EOF);
		putchar(c);
		c = getchar();
	}
	// Ctrl-D simulates EOF on UNIX
	printf("Value of c != EOF: %d\n", c != EOF);
}
*/

// Ex 1.9
/*
main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			putchar(c);
			while ((c = getchar()) == ' ') {
				;
			}
		}
		putchar(c);
	}
}
*/

// Ex 1.10

main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			printf("\n\\t\n");
		}
		else if (c == '\\') {
			printf("\n\\\\\n");
		}
		else if (c == '\b') {
			printf("\n\\b\n");
		}
		else {
			putchar(c);
		}
	}
}


