#include<iostream>
#include<stack>
#include<list>
#include<vector>
#include<queue>
using namespace std;

// Queue (FIFO : First In First Out) -> 선입선출
// 스택보다 많이 사용함.
// ex)은행 대기열, 롤 대기열, 커피 대기열...
//


// 순환 방식 : 어느 정도 벡터에서 중간 삽입 삭제가 느린 문제를 일단 해결할 수 있다.
// 순환 방식은 나중에 순환 버퍼에서도 사용한다.
// [] [] [front] [] [] [] [] [] [] [back] [] [] [] [] 
// [front] [] [] [] [] [] [] [back] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] ---> 2배 증설뒤, 복사 
template<typename T>
class ArrayQueue
{// 배열을 할당 받아서 순환 구조로 사용할 것이다.
public:

	ArrayQueue()
	{
		_container.resize(100);
	}

	void push(const T& value)
	{
		// TODO : 다 찼는지 체크
		if (_size == _container.size())
		{
			// 증설 작업
			int newSize = max(1, _size * 2);// 처음에는 사이즈가 0일 수 있으니까 0은 되지 않게 최소 1은 되게끔함.
			// 왼쪽, 오른쪽 값이랑 둘 중 더 큰 걸 리턴함.
			vector<T> newData;
			newData.resize(newSize);
			
			// 데이터 복사
			for (int i = 0; i < _size; i++)
			{
				int index = (_front + i) % _container.size();
				newData[i] = _container[index];
			}

			_container.swap(newData);
			_front = 0;
			_back = _size;

		}

		_container[_back] = value;
		_back = (_back + 1) % _container.size();// 순환 구조를 만들때 사용하는 유용한 테크닉!
		//  _container.size() : 버퍼의 크기
		_size++;// data의 개수

	}

	void pop()
	{
		_front = (_front + 1) % _container.size();
		_size--;
	}

	T& front()
	{
		return _container[_front];
	}

	bool empty() { return _size == 0; }
	int size() { return _size(); }

private:
	vector<T> _container;
	
	int _front = 0;
	int _back = 0;
	int _size = 0;
};


template<typename T>
class ListQueue
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}

	void pop()
	{
		//_container.erase(_container.begin());// vector에서 중간에 추가/삭제를 하는데 시간에 많이 걸림. --> 땡겨줘야하기 때문
		_container.pop_front();// 리스트일때 list
	}

	T& front()
	{
		return _container.front();
	}

	bool empty() { return _container.empty(); }
	int size() { return _container.size(); }

private:
	//vector<T> _container;
	list<T> _container;
};

int main()
{
	// 스택, 큐 둘다 deque를 기본 컨테이너로 활용한다.
	// deque는 배열과 리스트의 중간 사이
	queue<int> q;

	for (int i = 0; i < 100; i++)
	{
		q.push(i);
	}

	while (q.empty()==false)
	{
		int value = q.front();
		q.pop();
		cout << value << endl;
	}

	int size = q.size();



	return 0;
}