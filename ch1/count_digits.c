#include <stdio.h>

// count digits, white space, others

main () {
	int c;		  			// current char
	int i;		    		// index
	int nwhite;     		// white space accum
	int nother;     		// other accum
	int ndigit[10]; 		// digit array
	
	nwhite = nother = 0;	// init accums
	
	// for loop to init ndigit
	for (i = 0; i < 10; ++i) {
		ndigit[i] = 0;
	}
	
	// while more of the file remains
	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {	// if c is a digit
			++ndigit[c - '0']; 		// accum on the corresponding index
		} else if (c == ' ' || c == '\n' || c == '\t') {	// else if c is white space
			++nwhite;	// accum nwhite
		} else {		// else c is other
			++nother;	// accuum nother
		}
	}
	
	printf("digits =");
	for (i = 0; i < 10; ++i) {
		printf(" %d", ndigit[i]);
	}
	printf(", white space = %d, other = %d\n", nwhite, nother);
}