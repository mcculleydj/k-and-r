#include <stdio.h>

main()
{
	int c; // current char
	int vowels[5]; // histogram
	char lit_vowels[] = {'a', 'e', 'i', 'o', 'u'}; // literals 
	int i, j; // indices
	
	for (i = 0; i < 5; i++)
		vowels[i] = 0;
	
	while ((c = getchar()) != EOF) {
		if      (c == 'a') vowels[0]++;
		else if (c == 'e') vowels[1]++;
		else if (c == 'i') vowels[2]++;
		else if (c == 'o') vowels[3]++;
		else if (c == 'u') vowels[4]++;
	}
	
	for (i = 0; i < 5; i++) {
		printf("\n%c: ", lit_vowels[i]);
		for (j = 0; j < vowels[i]; j++) {
			printf("*");
		}
	}
	printf("\n");
}