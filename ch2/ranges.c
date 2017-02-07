/* Ex 2-1
 * Determine the ranges of char, short, int, and long
 * for both signed and unsigned variables.
 * This exercise is harder if done by direct computation.
 * Additionally, find the ranges of the floating point types.
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	// char:
	printf("char:\n");
	printf("CHAR_MIN:\t%d\n", CHAR_MIN);
	printf("CHAR_MAX:\t%d\n", CHAR_MAX);
	printf("UCHAR_MAX:\t%d\n", UCHAR_MAX);
	printf("SCHAR_MIN:\t%d\n", SCHAR_MIN);
	printf("SCHAR_MAX:\t%d\n", SCHAR_MAX);
	printf("\n");

	// short:
	printf("short:\n");
	printf("SHRT_MIN:\t%d\n", SHRT_MIN);
	printf("SHRT_MAX:\t%d\n", SHRT_MAX);
	printf("USHRT_MAX:\t%d\n", USHRT_MAX);
	printf("\n");

	// int:
	printf("int:\n");
	printf("INT_MIN:\t%d\n", INT_MIN);
	printf("INT_MAX:\t%d\n", INT_MAX);
	printf("UINT_MAX:\t%u\n", UINT_MAX);
	printf("\n");

	// long:
	printf("long:\n");
	printf("LONG_MIN:\t%ld\n", LONG_MIN);
	printf("LONG_MAX:\t%ld\n", LONG_MAX);
	printf("ULONG_MAX:\t%lu\n", ULONG_MAX);
	printf("\n");

	// float:
	printf("float:\n");
	printf("FLT_MIN:\t%f\n", FLT_MIN);
	printf("FLT_MAX:\t%f\n", FLT_MAX);
	printf("\n");

	// double:
	printf("double:\n");
	printf("DBL_MIN:\t%f\n", DBL_MIN);
	printf("DBL_MAX:\t%f\n", DBL_MAX);
	printf("\n");

	return 0;
}