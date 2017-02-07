#include <stdio.h>

#define BUFFER_1_SIZE 10000
#define BUFFER_2_SIZE 10500
#define MAX_LENGTH 50

int getText (char* buffer);

void wrapText (char* buff1, char* buff2, int len);

int main()
{
	char buff1[BUFFER_1_SIZE];
	char buff2[BUFFER_2_SIZE];
	int len;

	len = getText(buff1);
	wrapText(buff1, buff2, len);

	printf("\n%s\n", buff2);

	return 0;
}

int getText (char* buffer)
{
	int i;
	int c;

	i = 0;

	while((c = getchar()) != EOF) {

		buffer[i] = c;
		i++;

		if (i == BUFFER_1_SIZE - 1) {
			printf("Buffer overflow.\n");
			return -1;
		}
	}

	return i;
}

void wrapText(char* buff1, char* buff2, int len)
{
	int buff1cursor;
	int buff2cursor;
	int counter;
	int lastSpace1;
	int lastSpace2;

	buff1cursor = buff2cursor = counter = 0;
	lastSpace1 = lastSpace2 = -1;

	while (buff1cursor < len) {
		buff2[buff2cursor] = buff1[buff1cursor];
		if (buff1[buff1cursor] == '\n') {
			counter = 0;
			lastSpace1 = lastSpace2 = -1;
		} else if (buff1[buff1cursor] == ' ' || buff1[buff1cursor] == '\t') {
			lastSpace1 = buff1cursor;
			lastSpace2 = buff2cursor;
			counter++;
		} else {
			counter++;
		}

		if (counter == MAX_LENGTH) {
			if (lastSpace1 != -1) {
				buff2[lastSpace2] = '\n';
				buff1cursor = lastSpace1 + 1;
				buff2cursor = lastSpace2 + 1;
				lastSpace1 = lastSpace2 = -1;
				counter = 0;
			} else {
				buff2[buff2cursor - 1] = '-';
				buff2[buff2cursor] = '\n';
				buff2cursor++;
				buff1cursor--;
				lastSpace1 = lastSpace2 = -1;
				counter = 0;
			}
		} else {
			buff1cursor++;
			buff2cursor++;
		}
	}

	buff2[buff2cursor] = '\0';
}
