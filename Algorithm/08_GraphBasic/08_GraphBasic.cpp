// 08_GraphBasic.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
/*

그래프의 개념
->[현실 세계의 사물이나 추상적인 개념 간]의 [연결 관계]를 표현
정점(Vertex) : 데이터를 표현 (사물, 개념)
간선(Edge) : 정점들을 연결하는데 사용

ex) 그래프, 가중치 그래프, 방향 그래프, 

*/


#include <iostream>
#include <vector>
using namespace std;


void CreateGraph_1()
{
	struct Vertex
	{
		vector<Vertex*> edges;

	};

	vector<Vertex> v;

	v.resize(6);

	v[0].edges.push_back(&v[1]);
	v[0].edges.push_back(&v[3]);
	v[1].edges.push_back(&v[0]);
	v[1].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[3]);
	v[3].edges.push_back(&v[4]);
	v[5].edges.push_back(&v[4]);

	// Q) 0번 -> 3번 정점이 연결되어 있나요?
	bool connected = false;
	for (Vertex* edge : v[0].edges)
	{
		if (edge == &v[3])
		{
			connected = true;
			break;
		}
	}

}

void CreateGraph_2()
{
	struct Vertex
	{
		vector<Vertex*> edges;

	};

	vector<Vertex> v;

	v.resize(6);

	// 연결된 목록을 따로 관리
	// adjacent[n] -> n번째 정점과 연결된 정점 목록
	vector<vector<int>> adjacent(6);// -> 2차원 배열이라고 생각하기
	adjacent[0] = { 1,3 };
	adjacent[1] = { 0,2,3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

	// 정점이 100개
	// - 지하철 노선도 -> 서로 드문 드문 연결 (양옆, 환승역이라면 조금 더 ++)
	// - 페이스북 친구 -> 서로  빽빽하게 연결 ----> 모든 애들이 연결되어 있다면, 나중에 검색을 할때, 리스트를 일일히 순회해야함.
	// - - 


	// Q) 0번 -> 3번 정점이 연결되어 있나요?
	bool connected = false;
	for (int vertex : adjacent[0])
	{
		if (vertex == 3)
		{
			connected = true;
			break;
		}
	}


	//STL
	vector<int>& adj = adjacent[0];
	bool connected2 = (find(adj.begin(), adj.end(), 3) != adj.end());

}

void CreateGraph_3()
{
	struct Vertex
	{
		vector<Vertex*> edges;

	};

	vector<Vertex> v;

	v.resize(6);

	// 연결된 목록을 따로 관리
	// adjacent[n] -> n번째 정점과 연결된 정점 목록
	//
	//[x][o][x][o][x][x]
	//[o][x][o][o][x][x]
	//[x][x][x][x][x][x]
	//[x][x][x][x][o][x]
	//[x][x][x][x][x][x]
	//[x][x][x][x][o][x]
	// 장점 : 빠르게 접근 가능
	// 단점 : 메모리를 좀 많이 소모
	// 간선이 많은 경우 이점이 있는 방법!! --> 일반적으로 이 방법을 많이 사용.
	vector<vector<bool>> adjacent(6, vector<bool>(6, false));// 6줄을 false로 초기화
	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	// 정점이 100개
	// - 지하철 노선도 -> 서로 드문 드문 연결 (양옆, 환승역이라면 조금 더 ++)
	// - 페이스북 친구 -> 서로  빽빽하게 연결 ----> 모든 애들이 연결되어 있다면, 나중에 검색을 할때, 리스트를 일일히 순회해야함.
	// - - 


	// Q) 0번 -> 3번 정점이 연결되어 있나요?
	bool connected = adjacent[0][3];
	

	// 가중치 그래프
	vector<vector<int>> adjacent2 =
	{
		vector<int> {-1,15,-1,35,-1,-1},
		vector<int> {15,-1,+5,10,-1,-1},
		vector<int> {-1,-1,-1,-1,+5,-1},
		vector<int> {-1,-1,-1,-1,-1,-1},
		vector<int> {-1,-1,-1,-1,+5,-1},
	};




}


int main()
{

	CreateGraph_1();
	CreateGraph_2();
	CreateGraph_3();
	return 0;
}
