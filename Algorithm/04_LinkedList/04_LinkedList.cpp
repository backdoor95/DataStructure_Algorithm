

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
	Node() : _prev(nullptr), _next(nullptr), _data(T())
	{

	}
	/*
Q:
Node() : _prev(nullptr), _next(nullptr), _data(T()) 에서

_data에 T()를 넣어 초기화 하는데 이렇게 초기화 하니

_data가 0으로 초기화 

A:
---> 정수형의 기본값이 0이라서 그렇게 됩니다.
	*/

private:

	Node* _prev;
	Node* _next;
	T _data;

};

template<typename T>
class Iterator
{
public:
	Iterator() : _node(nullptr)
	{

	}

	Iterator(Node<T>* node) : _node(node)
	{

	}

	// ++it
	Iterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	// it++
	Iterator& operator++(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}

	// --it
	Iterator& operator--()
	{
		_node = _node->_prev;
		return *this;
	}


	// it--
	Iterator& operator--(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}

	// *it
	T& operator*()
	{
		return _node->_data;
	}

	bool operator==(const Iterator& other)
	{
		return _node == other._node;
	}

	bool operator!=(const Iterator& other)
	{
		return _node != other._node;
	}

public:
	Node<T>* _node;
};

template<typename T>
class List
{
public:
	List() : _size(0)
	{
		_head = new Node<T>();
		_tail = new Node<T>();
		_head->_next = _tail;
		_tail->_preb = _head;
	}

	~List()
	{
		while (_size > 0)
		{
			pop_back();
		}

		delete _head;
		delete _tail;
	}

	void push_back(const T& value)
	{
		AddNode(_tail, value);
	}

	void pop_back()
	{
		RemoveNode(_tail->_prev);
	}

	int size() { return _size; }

private:

	// [head] <-> [1] <-> [prevNode] <-> [before] <-> [tail]    ---- before
	// [head] <-> [1] <-> [prevNode] <-> [newNode] <-> [before] <-> [tail]  --- after
	Node<T>* AddNode(Node<T>* before, const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* prevNode = before->_prev;// 앞에 더미 노드가 없다면 null 체크를 해야함.

		prevNode->_next = newNode;
		newNode->_prev = prevNode;

		newNode->_next = before;
		before->_prev = newNode;

		_size++;

		return newNode;

	}


	// [head] <-> [1] <-> [prevNode] <-> [node] <-> [nextNode] <-> [tail]		---- before
	// [head] <-> [1] <-> [prevNode] <-> [nextNode] <-> [tail]					---- after
	Node<T>* RemoveNode(Node<T>* node)
	{
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;

		_size--;

		return nextNode;
	}

public:
	using iterator = Iterator<T>();

	iterator begin() { return iterator(_head->_next); }
	iterator end() { return iterator(_tail); }

	// it '앞에' 추가
	iterator insert(iterator it, const T& value)
	{
		Node<T>* node = AddNode(it._node, value);
		return iterator(node);
	}

	iterator erase(iterator it)
	{
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);

	}

private:
	Node<T>* _head;
	Node<T>* _tail;
	int	     _size;
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

