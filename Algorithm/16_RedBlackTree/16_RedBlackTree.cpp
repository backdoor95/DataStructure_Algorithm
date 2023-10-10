#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "BinarySearchTree.h"
#include<thread>

using namespace std;

// 오늘의 주제 : 이진 탐색 트리
//	Red Black Tree는 난이도가 높기 때문에 코딩 테스트에서 나올 가능성이 작다!! 
int main()
{
	BinarySearchTree bst;

	bst.Insert(30);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(10);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(20);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(25);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(40);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(50);
	bst.Print();
	this_thread::sleep_for(1s);


	bst.Delete(20);

	//bst.Print_Inorder();
	bst.Print();
}

