#include <stdio.h>

#define MAXLINE 100

/* rudimentary calculator */
int main()
{
	double sum, atof(char[]);
	char line[MAXLINE];
	int mygetline(char line[], int max);

	sum = 0;
	while (mygetline(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));
	return 0;
}

/* notes */
// %g uses the shorter of %e %f
// functional return types must be consistent
// across different source files
// the compiler cannot detect type errors
// for mygetline and atof in this case