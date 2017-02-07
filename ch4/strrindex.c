#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

/* function declarations */
int mygetline(char s[], int max);
int strrindex(char s[], char t[]);

char pattern[] = "it"; /* pattern to search for */

/* find all lines matching the pattern */

int main()
{
	char line[MAXLINE];
	int found = 0;
	while (mygetline(line, MAXLINE) > 0) {
		if (strrindex(line, pattern) >= 0) {
			printf("%d\n", strrindex(line, pattern));
			found++;
		}
	}
	return found;
}


/* getline: get line into s, return length */

int mygetline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

/* strindex: return index of t in s, -1 if none */

int strrindex(char s[], char t[])
{
	int i, j, k;
	int r = -1;
	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
			;
		}
		if (k > 0 && t[k] == '\0') {
			r = i;
		}
	}
	return r;
}

/* EOF */