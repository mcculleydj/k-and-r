/************************************** 
 * This program prints a table
 * of F -> C conversions for
 * values of F = {0, 20, 40, ... , 300}
 **************************************/

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20 

float fToC(float f);

float fToC(float f)
{
	return 5.0 / 9.0 * (f - 32.0);
}

main()
{
	float fahr;
	float cels;
	int lower;
	int upper;
	int step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	printf("F:\t C:\n");
	while (fahr <= upper) {
		cels = fToC(fahr);
		printf("%3.0f\t%6.1f\n", fahr, cels);
		fahr += step;
	}

	// Exercise 1.4

	printf("\n");
	cels = lower;
	printf("C:\t F:\n");
	while (cels <= upper) {
		fahr = 9.0 / 5.0 * cels + 32.0;
		printf("%3.0f\t%6.1f\n", cels, fahr);
		cels += step;
	}

	// Exercise 1.5 using for(){}
	int fahr2;
	printf("\nF:\t C:\n");
	for (fahr2 = UPPER; fahr2 >= LOWER; fahr2 -= STEP) {
		printf("%3d\t%6.1f\n", fahr2, (5.0 / 9.0 * (fahr2 - 32)));
	}
}