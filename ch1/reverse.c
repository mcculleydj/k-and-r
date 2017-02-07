#include <stdio.h>

#define MAXCHAR 1000 // maximum buffer size

int getLine(char s[], int maxchar);
void reverse(char s[], int len);

int main()
{
	char line[MAXCHAR];
	int len;

	while ((len = getLine(line, MAXCHAR)) > 0) {
		// debug
		/*
		printf("len: %d\n", len);
		line[len + 1] = '\0';
		printf("line: %s\n", line);
		*/

		reverse(line, len);
		line[len] = '\0';
		printf("%s\n", line);
	}

	return 0;
}

int getLine(char s[], int maxchar)
{
	int i;
	int c;

	for (i = 0; i < maxchar; i++) {
		c = getchar();
		if (c == EOF)
			break;
		else if (c == '\n') {
			break;
		}
		else
			s[i] = c;
	}

	return i;
}

void reverse(char s[], int len)
{
	int i;
	char temp;

	for (i = 0; i < len / 2; i++) {
		// debug
		// printf("%c\n", s[i]);

		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}
















