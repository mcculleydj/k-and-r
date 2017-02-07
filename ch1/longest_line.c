#include <stdio.h>
#define MAXLINE 1000

// function declarations:
int getLine(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
	int len;	// current len
	int max;	// current max len
	int c;		// curent char
	char line[MAXLINE];		// current line
	char longest[MAXLINE];	// current max line

	max = 0;	// init max

	// while there is a line to fetch:
	while ((len = getLine(line, MAXLINE)) > 0) {
		if (line[len - 1] != '\n') {
			while ((c = getchar()) != EOF && c != '\n') {
				len++;
			}
		}
		if (len > max) {	// if this line is the new max
			max = len;		// overwrite max
			copy(longest, line);	// overwrite longest
		}
	}

	// if there was at least one line:
	if (max > 0) {	
		printf("%s\n", longest);	// print the longest line
		printf("this line has %d characters\n", max);
	}
	return 0;	// exit
}

// fetch line and return its length
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

// copy the from char[] to the to char[]
void copy(char to[], char from[])
{
	int i;

	i = 0;
	// assign to[i] to from[i] and look for '\0'
	while ((to[i] = from[i]) != '\0') {
		i++;
	}
}





