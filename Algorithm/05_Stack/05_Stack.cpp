#include<iostream>
#include<stack>
#include<list>
#include<vector>
using namespace std;

// Stack (LIFO : Last In First Out) -> ���Լ���

// ���� ���� --> 1. �����迭 , 2.���Ḯ��Ʈ ������� ����� �ִ�.
// �ǵ�����(ctrl + z)

template<typename T, typename Container = vector<T>>// �⺻���¿����� ���ͷ� , ���Ḯ��Ʈ ������� �ٲٱ� ���� 
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
	//list<T> _container;// �������̽� ����ȭ�� ����!!, �׳� list���� ��ȯ�ص� �۵���!
	Container _container;
};

int main()
{
	Stack<int, list<int>> ss;// �̷��� ���Ḯ��Ʈ�� ������ �����ϴ�.
	// �����̸� �ѹ��� �ٲٱ�
	stack<int> s;

	// ����
	s.push(1);
	s.push(2);
	s.push(3);

	// �����?
	while (s.empty() == false)
	{	
		// �ֻ��� ����
		int data = s.top();
		// �ֻ��� ���� ����
		s.pop();

		cout << data << endl;
	}

	// ������
	int size = s.size();

	//����� ���� ���� ��쿡�� �ڵ� ���迡�� ����� ������ �׷� ���̵��� �����Դϴ�


	return 0;
}