﻿#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

// 오늘의 주제 : 이진 탐색 트리

// 이진 탐색(binary search)
// 상황) 배열에 데이터가 정렬되어 있다.-- 주의할것!

// Q) 82라는 숫자가 배열에 있습니까?
// A) O(N)
// [1][8][15][23][32][44][56][63][81][91]

// 업 다운 게임
// 81

// 정렬된 배열을 이용해서 이진 탐색 가능 
// - 잠깐! 그런데 배열의 단점은?
// // --중간 삽입/삭제가 느리다!
// 정렬된 연결리스트로는 불가 (임의접근이 안되기 때문!)
vector<int> numbers;

void BinarySearch(int N)
{
	int left = 0;
	int right = (int)numbers.size() - 1;

	while (left <= right)
	{
		cout << "탐색 범위: " << left << "-" << right << endl;
		int mid = (left + right) / 2;

		if (N < numbers[mid])
		{
			cout << N << " < " << numbers[mid] << endl;
			right = mid - 1;
		}
		else if (N > numbers[mid])
		{
			cout << N << " > " << numbers[mid] << endl;
			left = mid + 1;
		}
		else
		{
			cout << "찾음!" << endl;
			break;
		}
	}
}

int main()
{
	numbers = vector<int>{ 1,8,15,23,32,44,56,63,81,91 };

	BinarySearch(82);
}
