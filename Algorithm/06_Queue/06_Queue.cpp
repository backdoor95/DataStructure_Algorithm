#include<iostream>
#include<stack>
#include<list>
#include<vector>
#include<queue>
using namespace std;

// Queue (FIFO : First In First Out) -> ���Լ���
// ���ú��� ���� �����.
// ex)���� ��⿭, �� ��⿭, Ŀ�� ��⿭...
//


// ��ȯ ��� : ��� ���� ���Ϳ��� �߰� ���� ������ ���� ������ �ϴ� �ذ��� �� �ִ�.
// ��ȯ ����� ���߿� ��ȯ ���ۿ����� ����Ѵ�.
// [] [] [front] [] [] [] [] [] [] [back] [] [] [] [] 
// [front] [] [] [] [] [] [] [back] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] ---> 2�� ������, ���� 
template<typename T>
class ArrayQueue
{// �迭�� �Ҵ� �޾Ƽ� ��ȯ ������ ����� ���̴�.
public:

	ArrayQueue()
	{
		_container.resize(100);
	}

	void push(const T& value)
	{
		// TODO : �� á���� üũ
		if (_size == _container.size())
		{
			// ���� �۾�
			int newSize = max(1, _size * 2);// ó������ ����� 0�� �� �����ϱ� 0�� ���� �ʰ� �ּ� 1�� �ǰԲ���.
			// ����, ������ ���̶� �� �� �� ū �� ������.
			vector<T> newData;
			newData.resize(newSize);
			
			// ������ ����
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
		_back = (_back + 1) % _container.size();// ��ȯ ������ ���鶧 ����ϴ� ������ ��ũ��!
		//  _container.size() : ������ ũ��
		_size++;// data�� ����

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
		//_container.erase(_container.begin());// vector���� �߰��� �߰�/������ �ϴµ� �ð��� ���� �ɸ�. --> ��������ϱ� ����
		_container.pop_front();// ����Ʈ�϶� list
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
	// ����, ť �Ѵ� deque�� �⺻ �����̳ʷ� Ȱ���Ѵ�.
	// deque�� �迭�� ����Ʈ�� �߰� ����
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