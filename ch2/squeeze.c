#include <stdio.h>

void squeeze(char s1[], char s2[]);
void removeChar(char s[], char c);

int main()
{
	char s1[] = "remove the vowels from this string";
	char s2[] = "aeiou";

	squeeze(s1, s2);

	printf("The modified string: %s\n", s1);

	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i = 0;

	while (s2[i] != '\0') {
		removeChar(s1, s2[i]);
		i++;
	}
}

void removeChar(char s[], char c)
{
	int i = 0;
	int j = 0;

	while (s[i] != '\0') {
		if (s[i] != c) {
			s[j] = s[i];
			i++;
			j++;
		} else {
			i++;
		}
	}

	s[j] = '\0';
}