# -Algorithm
#include <stdio.h>
#include <math.h>

int Euclid(int a, int b);

int main() {
	printf("%d", Euclid(12, 2));
}


// mod 함수 사용
/*
int Euclid(int a, int b) {

	int A = a;
	int B = b;

	// check a > b
	if (A < B) {
		B = A;
	}

	if (B == 0) return A;
	return Euclid(B, fmod(A,B));
}
*/


// mod 함수 미사용
int Euclid(int a, int b) {

	int A = a;
	int B = b;

	// check a > b
	if (A < B) {
		B = A;
	}

	if (B == 0) return A;


	// (a, b ) => (b, a%b)
	int tmp = A % B;
	A = B;
	B = tmp;

	return Euclid(A, B);
}
