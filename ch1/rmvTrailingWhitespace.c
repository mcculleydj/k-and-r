#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
int lastChar(char line[], int len);

main()
{
	int len;				// current len
	int index;				// index of lastChar
	int i;					// index
	char line[MAXLINE];		// current line

	// printf("What is \\n: %d\n", '\n');

	while ((len = getLine(line, MAXLINE)) > 0) {
		index = lastChar(line, len);
		// printf("index is: %d\n", index);
		if (line[0] == '\n')
			;
		else {
			for (i = 0; i <= index; i++) {
				printf("%c", line[i]);
			}
			printf("\n");
		}
	}

	return 0;	// exit
}

int getLine(char s[], int lim)
{
	int c;	// current char
	int i;	// index

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		s[i] = c;
	}

	// if the for loop terminated as a result of '\n'
	if (c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0'; 	// tack on the end string char
	return i;
}

// returns the index of the last not white space character
int lastChar(char s[], int len)
{
	int ret_index;
	int i;

	ret_index = 0;

	for (i = 0; i < len; i++) {
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != EOF) {
			// printf("i: %d\ts[i]: %c\n", i, s[i]);
			ret_index = i;
		}
	}

	return ret_index;
}