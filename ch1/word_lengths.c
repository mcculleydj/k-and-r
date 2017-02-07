#include <stdio.h>

main()
{
	int state; 	  	// 0 if outside word, 1 if inside word
	int c;		  	// current char
	int len;	 	// word length
	int i, j;	 	// indices	
	int hist[20];	// histogram
	
	state = 0;   	// init state
	len = 0;		// init len 
	
	for (i = 0; i < 20; i++)	// init hist[]
		hist[i] = 0;
		
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == 1) {
				hist[len]++;
				len = 0;
			} 
			state = 0;
		} else {
			len++;
			state = 1;
		}
	}
	
	for (i = 0; i < 20; i++) {
		printf("\n%d: ", i);
		for (j = 0; j < hist[i]; j++) {
			printf("*");
		}
	}
}