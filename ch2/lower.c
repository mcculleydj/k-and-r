#include <stdio.h>

int lower(int c);
int lower2(int c);

int main()
{

	char c1 = 'A';
	char c2 = '*';
	char c3 = 'b';
	char c4 = 'Z';

	printf("lower(%c): %c\n", c1, lower(c1));
	printf("lower2(%c): %c\n", c1, lower2(c1));
	printf("lower(%c): %c\n", c2, lower(c2));
	printf("lower2(%c): %c\n", c2, lower2(c2));
	printf("lower(%c): %c\n", c3, lower(c3));
	printf("lower2(%c): %c\n", c3, lower2(c3));
	printf("lower(%c): %c\n", c4, lower(c4));
	printf("lower2(%c): %c\n", c4, lower2(c4));

	return 0;
}

int lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

int lower2(int c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}