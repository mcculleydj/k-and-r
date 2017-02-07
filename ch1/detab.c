#include <stdio.h>

#define SPACES_PER_TAB 4

int getBlock(char s[]);
void printBlock(char s[], int len);
void detabBlock(char s[], char detab_s[], int len);

int main()
{
	char s[SPACES_PER_TAB];
	char detab_s[SPACES_PER_TAB * SPACES_PER_TAB + 1]; // + 1 for '\0' char
	int len;
	
	while((len = getBlock(s)) > 0) {
		detabBlock(s, detab_s, len);
		printf("%s", detab_s);
	}
	
	printf("\n");
	
	return 0;
}

int getBlock(char s[])
{
	int i;
	int c;
	
	i = 0;
	
	while ((c = getchar()) != EOF) {
		// printf("getchar(): %c\n", c);
		if (c == '\n') {
			s[i] = '\n';
			i++;
			break;
		}
		if (i >= SPACES_PER_TAB - 1) {
			s[i] = c;
			i++;
			break;
		}
		s[i] = c;
		i++;
	}
	
	return i;
}

void printBlock(char s[], int len)
{
	int i;
	
	for (i = 0; i < len; i++) {
		printf("%c", s[i]);
	}
	
	printf("\n");
}

void detabBlock(char s[], char detab_s[], int len)
{
	int i;
	int j;
	int k;
	int spaces;
	
	j = 0;
	
	for (i = 0; i < len; i++) {
		if (s[i] == '\t') {
			spaces = len - (j % 4);
			for (k = 0; k < spaces; k++) {				
				detab_s[j] = ' ';
				j++;
				// printf("\nin for loop, new j: %d\n", j);
			}
		} else {
			// printf("\nno tab enc, i: %d, j: %d\n", i, j);
			detab_s[j] = s[i];
			j++;
		}
	}
	
	detab_s[j] = '\0';
}








