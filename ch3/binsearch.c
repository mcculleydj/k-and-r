#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
	int v[10] = {0, 1, 2, 3, 4, 5, 6, 7, 10, 15};
	int n = 10;
	int x = 2;

	printf("binsearch(%d): %d\n", x, binsearch(x, v, n));

	return 0;
}

int binsearch(int x, int v[], int n)
{
	int low, mid, high;

	low = 0;
	high = n - 1;

	while (low <= high) {
		
		mid = (low + high) / 2;
		
		if (x == v[mid]) {
			printf("target found!\n");
			return v[mid];
		}

		if (x <= v[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	return -1;
}