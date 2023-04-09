#include <stdio.h>

//재귀적 방법
int euclid(int a, int b)
{

    //1. If(b = 0) return a  // 종료조건 of 재귀호출!
    if (b == 0) return a;
    
    //2. return Euclid(b, a mod b)
    return euclid(b, a % b);

}
//반복적 방법
int loop_method(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}


int test1_euclid()
{
    int gcd = 0;

    gcd = euclid(34, 48);
    printf("Hello World! %d\n", gcd);

    return 0;
}