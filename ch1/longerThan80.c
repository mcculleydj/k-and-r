#include <stdio.h>
#define MINLINE 80
#define MAXLINE 1000

int getLine(char line[], int maxline);

main()
{
	int  len;				// current len
	char line[MAXLINE];		// current line

	while ((len = getLine(line, MAXLINE)) > 0) {
		if (len > MINLINE) {
			printf("%s\n", line);
		}
	}

	return 0;	// exit
}

int getLine(char s[], int lim)
{
	int c;	// current char
	int i;	// index

	// for i < MAXLINE
	// assign c and ensure that it isn't EOF
	// finally, test for c == '\n'
	// accumulate the string on s[] (line)
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		s[i] = c;
	}

	// if the for loop terminated as a result of '\n'
	if (c == '\n') {
		s[i] = c;
		i++;
	}
	s[i] = '\0'; 	// tack on the end string char
	return i;		// return length
}