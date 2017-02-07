// Ex 5-1
// Fix getint to push '+' or '-' not immediately
// followed by a digit back onto the stack.

#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;

int getch(void) /* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("error: buffer overflow\n");
	else
		buf[bufp++] = c;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch())) /* skip white space */
		;
	
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* c is not a char we care about */
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	
	if (c == '+' || c == '-')
		ungetch(c);
	
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	
	*pn *= sign;
	
	if (c != EOF)
		ungetch(c);
	
	return c;
}

/* unit test */
int main()
{
	int *pn;
	getint(pn);
	printf("*pn: %d\n", *pn);

	return 0;
}

/* EOF */