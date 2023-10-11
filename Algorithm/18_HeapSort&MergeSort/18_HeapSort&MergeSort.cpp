#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// 오늘의 주제 : 힙 정렬| 병합 정렬

// 힙 정렬
void HeapSort(vector<int>& v)
{
	//힙 구조는 최소&최대에 해당하는 데이터를 뽑을때 굉장히 최적화가 되어있다.
	// priority_queue는 힙 구조으로 되어있다. 

	priority_queue<int, vector<int>, greater<int>> pq;

	// O(N*logN)
	for (int num : v)
	{
		pq.push(num);
	}

	v.clear();

	// O(N*logN)
	while (pq.empty() == false)
	{
		v.push_back(pq.top());
		pq.pop();
	}

}

// 병합 정렬
// 분할 정복 (Divide and Conquer)
// - 분할 (Divide)		문제를 더 단순하게 분할한다.
// - 정복 (Conquer)		분할된 문제를 해결
// - 결합 (Combine)		결과를 취합하여 마무리

// 문제를 분할해서 각각 다른 애들이 실행을 하게끔 만들어줄수 있으니까
// 나중에 멀티스레드 환경에서도 굉장히 유용함.

// [3][K][7][2][J][4][8][9]					8개 * 1
// [3][K][7][2]  [J][4][8][9]				4개 * 2
// [3][K]  [7][2]  [J][4]  [8][9]			2개 * 4
// [3]  [K]  [7]  [2]  [J]  [4]  [8]  [9]	1개 * 8
// [3][K]  [2][7]  [4][J]  [8][9]			2개 * 4
// [2][3][7][K]  [4][8][9][J]  				4개 * 2
// [2][3][4][7][8][9][J][K]					8개 * 1

// MergeResult의 시간복잡도 : O(N) 
void MergeResult(vector<int>& v, int left, int mid, int right)
{

	int leftIdx = left;
	int rightIdx = mid + 1;

	vector<int> temp;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (v[leftIdx] <= v[rightIdx])
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
		else
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}

	// 왼쪽이 먼저 끝났으면, 오른쪽 나머지 데이터 복사
	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}
	else// 오른쪽이 먼저 끝났으면, 왼쪽 나머지 데이터 복사
	{
		while (leftIdx <= mid)
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
	{
		v[left + i] = temp[i];
	}

}

// MergeSort의 시간복잡도 : O(logN)
void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right)/ 2;
	MergeSort(v, left, mid);// 4
	MergeSort(v, mid + 1, right);// 4

	MergeResult(v, left, mid, right);
}

int main()
{
	vector<int> v;

	srand(time(0));

	for (int i = 0; i < 50; i++)
	{
		int randValue = rand() % 100;
		v.push_back(randValue);
	}

	//HeapSort(v);

	MergeSort(v, 0, v.size() - 1);
}

