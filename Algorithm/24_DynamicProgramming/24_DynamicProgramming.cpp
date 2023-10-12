#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<thread>
#include<windows.h>

using namespace std;


// 오늘의 주제 : 동적 계획법 (DP)

// 메모이제이션( memoization )
int cache[50][50];


/*
Combination(이항 계수)

n       n-1     n-1
   =  
r       r-1      r
*/

int g_count;
int cache[50][50];


int combination(int n, int r)
{
    // 기저 사례
    if (r == 0 || n == r)
        return 1;

    // 2C1  나중에 동영상 참고해라. 이 부분이 많이 중복이 되기 때문에 캐시에 따로 저장해서 하면 속도 증가를 노릴수있다.
    if (n == 2 && r == 1)
        g_count++;

    // 이미 답을 구한 적 있으면 바로 반환
    int& ret = cache[n][r];
    if (ret != -1)
        return ret;
    
    // 새로 답을 구해서 캐시에 저장
    return ret = combination(n - 1, r - 1) + combination(n - 1, r);
}

int main()
{
    memset(cache, -1, sizeof(cache)); // -1로 싸그리 초기화

    __int64 start = GetTickCount64();

    int lotto = combination(45, 6);

    __int64 end = GetTickCount64();

    cout << g_count << endl;

    cout << end - start << " ms" << endl;

    // 동적계획법이란 문제를 쪼개고 해결 --> 기존에 구한 값이 있으면 개를 재사용한다는게 가장 핵심.
    // 코딩 문제에서는 자주 나온다!

}

