#include <stdio.h>

// parses the std-in looking for EOF
// or termination character
// populates the buffer s[]
// returns the length of the line
// stored in s[]

int mygetline(char s[], int lim)
{
	int c, i;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* notes */
// s[] should have a size of lim
// lim is the max number of chars
// the while loop will process for each line