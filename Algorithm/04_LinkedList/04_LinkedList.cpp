

#include <iostream>
#include<vector>
#include<list>

using namespace std;

/*
연속되어 있다는 특징 덕분에 사실 컴퓨터 구조에서 캐시 덕도 볼 수 있고 굉장히 장점이
많습니다 그래서 효율성 측면에서 벡터가 압도적이기 때문에 대부분의 경우는 벡터를 사용할
것이다 라는 건 일단 알 수 있지만 그럼에도 불구하고 리스트가 굉장히 중요한 이유가 앞으로
나중에 공부할 다른 자료구조들의 기초가 되는 놈이기 때문.
*/

template<typename T>
class Node
{
public:

private:

};


int main()
{
	
	list<int> li;

	list<int>::iterator eraseIt;

	// [	] [		] [		]
	for (int i = 0; i < 10; i++)
	{
		if (i==5)
		{
			eraseIt = li.insert(li.end(), i);// 내가 넣어줄 위치의 바로 다음 위치임.
		}
		else
		{
			li.push_back(i);
		}
	}

	li.pop_back();// 뒤에 데이타 빼기

	li.erase(eraseIt);// 중간에 있던 데이터 삭제

	for (list<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		cout << *it << endl;
	}


	return 0;
}

