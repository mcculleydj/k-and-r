#include <stdio.h>

void qsort(int v[], int left, int right)
{
	int i, pivot_index;
	void swap(int v[], int i, int j);

	// base case fewer than two elements:
	if (left >= right) return;

	// select first element as the pivot:
	pivot_index = left;

	for (i = left+1; i <= right; i++) {
		if (v[i] < v[left]) {
			swap(v, ++pivot_index, i);
		}
	}

	swap(v, left, pivot_index);

	qsort(v, left, pivot_index-1);
	qsort(v, pivot_index+1, right);
}

void swap(int v[], int i, int j)
{
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int main()
{
	int v[] = {4, 5, 2, 6, 1, -2, 5, 9};
	qsort(v, 0, 7);
	for (int i = 0; i < 8; i++)
		printf("%d ", v[i]);
	printf("\n");
	return 0;
}

// EOF