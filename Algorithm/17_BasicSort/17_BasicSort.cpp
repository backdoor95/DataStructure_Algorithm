
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 오늘의 주제 : 정렬---> 면접!! 자주나옴.

// 이진 트리는 대부부느 log N을 보장함.
// Sorting ?

// 1) 버블 정렬(Bubble Sort) ---> 첫째턴 뒤쪽에 가장큰놈이 확정됨.!
// 왜 버블인가?
// 하나 단위로 거품단위로 동작하는 느낌이기 때문
// 직관적이고 구현하는게 쉽다. 단, 효율성은 최악이다.
void BubbleSort(vector<int>& v)
{
	const int n = (int)v.size();

	// (N-1)+(N-2)+....+2+1 = N*(N-1)/2 ==O(N^2) -> 현실적으로 실전에서는 못씀.

	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < (n-1-i); j++)
		{
			if (v[j] > v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

// 2) 선택 정렬(Selection Sort)
// 스캔을 하면서 가장 작은놈을 왼쪽에 배치
// 그 다음에 작은놈을 2번째 왼쪽에 배치
// 버블정렬은 2개를 비교함..
void SelectionSort(vector<int>& v)
{
	const int n = (int)v.size();

	for (int i = 0; i < n-1; i++)
	{
		int bestIdx = i;
		for (int j = i+1; j < n; j++)
		{
			if (v[j] < v[bestIdx])
				bestIdx = j;
		}

		// 교환
		int temp = v[i];
		v[i] = v[bestIdx];
		v[bestIdx] = temp;
	}
}

// 3) 삽입 정렬(Insertion Sort)
// 코딩면접에서 잘나옴.
// 삽입정렬에 사용된 테크닉이 코딩문제에서도 잘나옴.
// 느낌이 선택정렬과 비슷함.
// 만약 운이 좋게 대부분의 데이터들이 정렬이 되있는 상태라면 더 효율적으로 동작할수 있는 확률이 있다.
// 일반적인 상황에서는 삽입 정렬이 딱히 효율적이지는 않다.
void InsertionSort(vector<int>& v)
{
	const int n = (int)v.size();
	for (int i = 1; i < n; i++)
	{
		int insertData = v[i];
		int j;

		for (j = i - 1; j >= 0; j--)
		{
			if (v[j] > insertData)
				v[j + 1] = v[j];
			else
				break;
		}

		v[j + 1] = insertData;

	}
}

// 여기서 O(N^2)
int main()
{
	vector<int> v{ 1,5,3,4,2 };

	BubbleSort(v);
	SelectionSort(v);
	InsertionSort(v);

	return 0;
}

