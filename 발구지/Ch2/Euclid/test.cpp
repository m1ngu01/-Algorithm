//test case
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "euclid.h"

//매우 큰 두수의 쌍 N개 설정

void test(int TIME) {
	//랜덤 시드값 설정 (unsinged)을 통해 음수값 x
	srand((unsigned)time(NULL));

	int a = rand();
	int b = rand();
	int i = 0;

	while (i < TIME) {
		//무작위 두 숫자 설정
		a = rand();
		b = rand();

		euclid(a, b);
		loop_method(a, b);

		//두 함수의 결과가 다를 시 [에러] 출력 후 반복문 탈출
		if (euclid(a, b) != loop_method(a, b)) {
			printf("error");
			break;
		}
		printf("%d --- %d\n", euclid(a, b), i);
		i++;
	}
}