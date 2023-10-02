
#include <iostream>
#include<vector>
using namespace std;

template<typename T>
class Vector
{
public:
	Vector()
	{

	}
	~Vector()
	{
		if (_data)
			delete[] _data;
	}
	void push_back(const T& value)
	{
		if (_size == _capacity)
		{
			// 증설 작업
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);

		}

		// 데이터 저장
		_data[_size] = value;
		
		// 데이터 개수 증가
		_size++;

	}

	void reserve(int capacity)
	{
		if (_capacity >= capacity)
			return;

		_capacity = capacity;

		T* newData = new T[_capacity];

		// 데이터 복사
		for (int i = 0; i < _size; i++)
		{
			newData[i] = _data[i];
		}

		if (_data)
			delete _data;

		// 교체
		_data = newData;

	}

	T& operator[](const int pos) { return _data[pos]; }

	int size() { return _size; }
	int capacity() { return _capacity; }

	void clear()
	{
		if (_data)
		{
			delete[] _data;
			_data = new T[_capacity];
		}

		_size = 0;
	}

private:
	T* _data = nullptr;
	int _size = 0; // 실질적인 데이터 개수
	int _capacity = 0; // 방의 개수
};

int main()
{
	vector<int>	v;

	v.resize(10);// size를 조정하는것!, 실제 데이터 개수를 애가 막바로 조정을 하게됨. ---> capacity도 같이 변한다.
	cout << v.size() << " "<< v.capacity()<<endl;
	cout << v[0] << " " << v[1] << endl; // size 를 10으로 세팅 헀다면 0으로 초기화 되는듯.!

	v.reserve(100);
	cout << v.size() << " "<< v.capacity()<<endl;


	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v.size() << " "<< v.capacity()<<endl;
	}

	v.resize(10);
	// 나먼지 90개 데이터 날라감.

	cout << v.size() << " "<< v.capacity()<<endl;
	//cout << v[20] << endl; // 만약에 resize를 벗어난 인덱스를 접근하려고 하면 assertion failed 발생함.
	// vector subscript out of range 에러 발생함.


	v.clear();
	cout << v.size() << " "<< v.capacity()<<endl;

	/*
	console output
1 1
2 2
3 3
4 4
5 6
6 6
7 9
8 9
9 9
10 13
11 13
.
.
.
97 141
98 141
99 141
100 141
0 141

동적 배열의 특성상 중요한 것은 이사 횟수를 최소화하는것!
	*/
	

	// 직접 만든 vector

	Vector<int> v2;

	// 처음부터 몇 개의 데이터를 사용할지를 예측할 수 있다면, reserve를 활용해서 충분한 양(capacity)를 예약을 하고 사용하는것이 훨씬 더 효율적이다.
	v2.reserve(100);
	cout << v.size() << " " << v.capacity() << endl;

	for (int i = 0; i < 100; i++)
	{
		v2.push_back(i);
		cout << v2.size() << " " << v2.capacity() << endl;
	}

	v2.clear();

	cout << v.size() << " " << v.capacity() << endl;

	///////////////////////////////////////

	/*
	면접을 볼 때 코딩 문제에서 이 벡터 구현은 은근히 자주 나오는 주제이다. ___. 중요!!!
	이런걸 연습하면 도움이 될것이다.
	
	*/

}

