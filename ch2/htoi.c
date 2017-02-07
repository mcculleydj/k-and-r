/*
 * Exercise 2-3
 * Convert a string a of hex to the equivalent integer.
 * Must handle an optional 0x or 0X and the standard hex set:
 * 0-9, a-f, and A-F.
 */

 #include <stdio.h>
 #include <ctype.h>
 #include <string.h>
 #include <math.h>

 int h_to_i(char h);

 int main()
 {
 	int c0;
 	int c1;
 	int c;
 	int i;
 	int j;
 	int n;
 	int was0x;
 	char s[128];

 	i = 0;
 	was0x = 0;

 	while ((c = getchar()) != EOF) {
 		if (i > 127) {
 			printf("Buffer overflow.\n");
 			return -1;
 		}

 		// handle the possibility of a "0X" or "0x":

 		if (i == 0) 		// first iteration
 			c0 = c;
 		else if (i == 1) 	// second iteration
 			c1 = c;
 		else if (i == 2) { 	// third iteration
 							// leading "0x" or "0X"
 			if (c0 == '0' && (c1 == 'x' || c1 == 'X')) {
 				s[0] = c;	// start building string at c2
 				was0x = 1;
 			} else { 		// no leading "0x" or "0X"
 				s[0] = c0;
 				s[1] = c1;
 				s[2] = c;
 			}
 		} else {
 			if (was0x)
 				s[i - 2] = c; 		// build the rest of the string
 			else
 				s[i] = c;
 		}

 		i++;
 	}

 	// handle inputs with fewer than 3 characters:

 	if (i == 0)
 		return 0;
 	else if (i == 1)
 		s[0] = c0;
 	else if (i == 2) {
 		s[0] = c0;
 		s[1] = c1;
 	}

 	if (was0x)
 		s[i - 2] = '\0'; 			// add a terminating null char
 	else
 		s[i] = '\0';

 	printf("String is: %s\n", s);

 	j = 0;
 	n = 0;

 	for (i = strlen(s) - 1; i >= 0; i--) {
 		printf("Current char: %c\n", s[i]);
 		printf("Current int_val: %d\n", h_to_i(s[i]));
 		printf("Current mult: %d\n\n", ((int)pow(16.0, (double)j)));

 		n = n + h_to_i(s[i]) * ((int)pow(16.0, (double)j));
 		j++;
 	}

 	printf("The integer value of this hex number is: %d\n", n);
 }

 int h_to_i(char h)
 {
 	if (isdigit(h))
 		return h - '0';
 	else if (h >= 'A' && h <= 'F')
 		return 10 + h - 'A';
 	else if (h >= 'a' && h <= 'f')
 		return 10 + h - 'a';
 	else
 		printf("Non-hex character detected: %c\n", h);
 		return -1;
 }