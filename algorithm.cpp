#include <stdio.h>

void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int medians(int a[], int left, int right) {
	int mid = (left + right) / 2;
	if (((a[left] > a[mid]) && (a[left] < a[right])) || ((a[left] > a[right]) && (a[left] < a[mid]))) return left;
	if (((a[mid] > a[right]) && (a[mid] < a[left])) || ((a[mid] > a[left]) && (a[mid] < a[right]))) return a[mid];
	if (((a[right] > a[left]) && (a[right] < a[mid])) || ((a[right] > a[mid]) && (a[right] < a[left]))) return right;
}

void dividesort(int a[], int left, int right) {
	
	int p = medians(a, left, right);

	printf("pivovt = %d [%d]\n", p, a[p]);

	swap(&a[left], &a[p]);
	p = left;

	while (right - left > 1) {
		left++;
		while (a[left] >= a[p]) {
			if (a[right] < a[p])
				swap(&a[left], &a[right]);
			else
				right--;
		}
	}
	swap(&a[p], &a[left]);
}

int main() {
	int a[] = { 8,4,3,1,66,4,2,77,9,4,1,3,5,7,8,9 };
	int n = sizeof(a) / sizeof(a[0]);

	dividesort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

}