#include <stdio.h>
int weight(int a, int b, int c, int d) {
	int fake = 55;
	if (a <= fake && fake <= b)
		return -1;
	if (c <= fake && fake <= d)
		return 1;
	return 0;
}
int find_fakecoin(int left, int right) {
	int i = left + 1;
	for (i; i <= right; i++) {
		int result = weight(left, left, i, i);
		if (result == -1) {
			return left;
		}
		else if (result == 1) {
			return i;
		}
	}
	return -1;
}

int main(void)
{
	int n = 100;
	printf("%d\n", find_fakecoin(0, n - 1));
	return 0;
}