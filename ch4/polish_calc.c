#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h>

#define MAXOP 100   // max size of operand or operator
#define MAXVAL 100  // max depth of the value stack
#define NUMBER '0'  // signal that a number was found
#define BUFSIZE 100 // max size of ungetch() buffer

// function declarations
int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

// global variables
int sp = 0; 		// stack ptr
double val[MAXVAL]; // stack
char buf[BUFSIZE];  // buffer for ungetch()
int bp = 0;			// buffer ptr

// reverse Polish calculator
int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: divide by zero\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

// standard stack push(obj)
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack overflow\n");
}

// standard stack pop()
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack underflow\n");
		return 0.0;
	}
}

/* getop: get next operator or operand */
int getop(char s[])
{
	int i, c;

	// why are we not using isspace()?
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';
	
	if (!isdigit(c) && c != '.')
		return c; /* not a number */
	
	i = 0;
	
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;

	if (c == '.') /* collect fractional part */
		while (isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';

	if (c != EOF)
		ungetch(c);

	return NUMBER;
}

int getch(void)
{
	return (bp > 0) ? buf[--bp] : getchar();
}

void ungetch(int c)
{
	if (bp >= BUFSIZE)
		printf("error: character buffer overflow\n");
	else
		buf[bp++] = c;
}