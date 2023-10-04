#include<iostream>
#include<stack>
#include<list>
#include<vector>
using namespace std;

// Stack (LIFO : Last In First Out) -> 후입선출

// 스택 응용 --> 1. 동적배열 , 2.연결리스트 방식으로 만들수 있다.
// 되돌리기(ctrl + z)

template<typename T, typename Container = vector<T>>// 기본상태에서는 벡터로 , 연결리스트 방식으로 바꾸기 가능 
class Stack
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}

	void pop()
	{
		_container.pop_back();
	}

	T& top()
	{
		return _container.back();
	}

	bool empty() { return _container.empty(); }
	int size() { return _container.size(); }

private:
	//vector<T> _container;
	//list<T> _container;// 인터페이스 통일화의 장점!!, 그냥 list으로 변환해도 작동함!
	Container _container;
};

int main()
{
	Stack<int, list<int>> ss;// 이렇게 연결리스트로 설정이 가능하다.
	// 변수이름 한번에 바꾸기
	stack<int> s;

	// 삽입
	s.push(1);
	s.push(2);
	s.push(3);

	// 비었나?
	while (s.empty() == false)
	{	
		// 최상위 원소
		int data = s.top();
		// 최상위 원소 삭제
		s.pop();

		cout << data << endl;
	}

	// 사이즈
	int size = s.size();

	//참고로 스택 같은 경우에도 코딩 시험에서 충분히 낼만한 그런 난이도의 문제입니다


	return 0;
}