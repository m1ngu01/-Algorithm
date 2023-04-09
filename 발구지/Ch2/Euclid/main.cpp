/*
* 프로그램 내용 : 헤더파일을 이용한 파일 분할법, 최대 공약수 구하기, 프로그램 실행 시간 측정
* 학번 : 202011309
* 이름 : 임민규
*/
//메인 함수
#include "euclid.h"
#include <stdio.h>
#include <time.h>

#define TIME 5000

int main() {

	time_t start, end;
	double result;

	//측정 시작
	start = time(NULL);

	euclid(10, 20);
	loop_method(10, 20);
	test1_euclid();
	test(TIME);
	//측정 끝
	end = time(NULL);
	//측정 데이터 계산
	result = (double)(end - start);

	printf("%lf", result);

	/*type2 clock()
	* clock_t start, end;
	* double reulst;
	* start = clock();
	* 수행할 코드
	* end = clock();
	* result = (double)(end - start);
	* 결과 출력 
	*/

	return 0;
}