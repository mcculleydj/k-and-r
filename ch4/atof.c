#include <ctype.h>
#include <stdio.h>

/* atof: converts string s into equivalent double */
/* does not handle input errors */

double atof(char s[])
{
	/* variable declaration */
	double val, power;
	int i, sign;

	/* skip leading white space */
	for (i=0; isspace(s[i]); i++)
		;

	/* parse leading '-' character */
	sign = (s[i] == '-') ? -1 : 1;
	
	/* skip single leading '+' and '-' character */
	if (s[i] == '+' || s[i] == '-')
		i++;

	/* the first digit is multiplied by 10.0 during each iter */
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0'); // ASCII
	
	/* skip decimal */
	if (s[i] == '.')
		i++;
	
	/* power: 10.0^d | d: number of digits following '.' */
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	
	return sign * val / power;
}

/* unit test */
// int main()
// {
// 	char s[] = "123.45";
// 	printf("%f\n", atof(s));
// 	return 0;
// }