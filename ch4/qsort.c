#include <stdio.h>

/* qsort: sort v[left]...v[right] into increasing order */

void qsort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right) return; /* single or null element */

	// this swap moves the middle element to left index
	swap(v, left, (left + right) / 2);
	
	// think of last as where the pivot needs to return to
	// once all comparisons have been made
	last = left;

	for (i = left+1; i <= right; i++) {
		if (v[i] < v[left]) {
			swap(v, ++last, i); // move the element to the left side
		}
	}
	swap(v, left, last); // put pivot at end of all elements < pivot
	// recursive calls on the left and right sides of the pivot
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap the ith and jth elements of v */
void swap(int v[], int i, int j)
{
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* unit test */
int main()
{
	int v[] = {4, 5, 2, 6, 1, -2, 5, 9};
	
	qsort(v, 0, 7);

	printf("{");
	for (int i = 0; i < 7; i++) {
		printf("%d", v[i]);
		printf(", ");
	}
	printf("%d}\n", v[7]);


	return 0;
}