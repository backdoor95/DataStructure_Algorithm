#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<thread>
#include<windows.h>

using namespace std;

// 오늘의 주제 : 동적계획법 dp
// enchant

// 집행검 0강

// +N강 집행검 뜨는 경우의 수는?
// 무기 강화 주문서 -> +1/ +2 / +3 중 하나


int N;
int cache[100];

// +num 에서 +N 까지 가는 경우의 수
int Enchant(int num)
{
	// 기저 사례
	if (num > N)
		return 0;

	if (num == N)
		return 1;

	// 캐시
	int& ret = cache[num];
	if (ret != -1)
		return ret;


	// 적용
	int ret = Enchant(num + 1) + Enchant(num + 2) + Enchant(num + 3);

}


int main()
{
	N = 9;

	memset(cache, -1, sizeof(cache));
	int ret = Enchant(0);
	cout << ret << endl;
}

