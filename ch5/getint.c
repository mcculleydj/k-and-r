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
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

	// getch() is a keyboard listener
	// getchar() is a stdin listener

	while (isspace(c = getch())) /* skip white space */
		;
	
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* c is not a char we care about */
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	
	if (c == '+' || c == '-')
		c = getch();
	
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
	return 0;
}

/* EOF */