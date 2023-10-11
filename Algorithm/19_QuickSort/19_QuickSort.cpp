#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
// 이번 주제: quick sort

int Partition(vector<int>& v, int left, int right)
{
    int pivot = v[left];// 무조건 첫번째 값이 피벗이된다.
    int low = left + 1;
    int high = right;

    // O(N)
    while (low <= high)
    {
        while (low <= right && pivot >= v[low])
        {
            low++;
        }
        while ( high >= left + 1 && pivot <= v[high] ) // 인덱스를 먼저 걸러줘야하기 때문에  high >= left + 1 를 먼저 사용
        {
            high--;
        }
        if (low < high)
            swap(v[low], v[high]);
    }
    swap(v[left], v[right]);
    return high;
}
// 최악의 경우 O(N^2) --> 파티션을 n번 호출할 경우|| 
// 평균 : O(NlogN)
// 병합정렬 같은 경우 시간복잡도가 nlogN 이라고 해도 실제로 테스트 해보면 차이가 난다.
// 병합 정렬같은 경우는 임시 벡터를 만들어가지고 임시 공간에 다가 데이터를 저장하고 다시꺼내고 하는 부분이 있기 때문에 조금 느리게 동작함.
// 반면에 퀵 정렬은 이런 불필요하게 데이터를 복사하는 것이 없기 때문에 빠르게 동작함.
void QuickSort(vector<int>& v, int left, int right)
{
    if (left > right)
        return;

    int pivot = Partition(v, left, right);
    QuickSort(v, left, pivot - 1); // 왼쪽
    QuickSort(v, pivot + 1, right); // 오른쪽
}
int main()
{
    srand(time(0));
    // pivot : 기준점.
    vector<int> v;
    for (int i = 0; i < 50; i++)
    {
        int randValue = rand() % 100;
        v.push_back(randValue);
    }
    QuickSort(v, 0, v.size() - 1);
}

