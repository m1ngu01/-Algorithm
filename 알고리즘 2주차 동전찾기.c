// 가짜 동전 찾는 프로그램
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 가짜 동전과 진짜 동전을 구별하는 함수


int weight(int fakecoin, int i){
    if(fakecoin == i) // 비교하는 위치가 가짜 동전 위치와 같다면
        return -1;
    if(i < 50) // 가짜 동전이 왼쪽 그룹에 있다면
        return 1;
    if(i > 50) // 가짜 동전이 오른쪽 그룹에 있다면
        return 0;
    else// 비교하지 않은 동전에 가짜 동전이 있다는 것을 의미
    	return -1;
}

// 가짜 동전을 찾는 함수 

int find_fakecoin(int n){
    int fakecoin = rand() % n; // 가짜 동전의 위치를 랜덤으로 설정 
    int left = 0; // 왼쪽 그룹의 첫번째 동전
    int right = n; // 오른쪽 그룹의 마지막 동전
    while(left < right){ // 동전 그룹의 개수가 1이 될 때까지 반복
        int half = (left + right) / 2; // 그룹을 반으로 나눔 
        int result = weight(fakecoin, half); // 무게 비교 결과를 저장
        if(result == -1) // 비교하는 위치가 가짜 동전 위치와 같다면 가짜 동전 위치 반환
            return fakecoin;
        else if(result == 1) // 왼쪽 그룹이 더 가벼운 경우 왼쪽 그룹을 다시 비교
            right = half - 1;
        else if(result == 0) // 오른쪽 그룹이 더 가벼운 경우 오른쪽 그룹을 비교
            left = half + 1;
        else
            return find_fakecoin(n-2); // 비교하지 않은 동전 중 가짜 동전 찾기
    }
}

int main(void)
{
    int n = 100;
    srand(time(NULL));
    printf("가짜 동전의 위치는: %d번째\n", find_fakecoin(n)); // 가짜 동전 위치 출력
    return 0;
}
