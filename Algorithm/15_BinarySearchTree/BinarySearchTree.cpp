#include "BinarySearchTree.h"
#include<iostream>
#include<windows.h>
using namespace std;

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}


void BinarySearchTree::Print(Node* node, int x, int y)
{
	if (node == nullptr)
		return;

	SetCursorPosition(x, y);
	cout << node->key;
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);

}

void BinarySearchTree::Print_Inorder(Node* node)
{
	// 전위 순회 (preorder traverse)

	// 중위 순회 (inorder)

	// 후위 순회 (postorder)

	if (node == nullptr)
		return;

	// 전위 : [중]이 앞에 온다
	// 중위 : [중]이 중간에 온다
	// 후위 : [중]이 마지막에 온다
	// [중][좌][우]

	// 전위
	cout << node->key << endl;
	Print_Inorder(node->left);
	Print_Inorder(node->right);

	//// 중위
	//Print_Inorder(node->left);
	//cout << node->key << endl;
	//Print_Inorder(node->right);

	//// 후위
	//Print_Inorder(node->left);
	//Print_Inorder(node->right);
	//cout << node->key << endl;

}

Node* BinarySearchTree::Search(Node* node, int key) // 1.재귀함수
{
	if (node == nullptr || key == node->key)
		return node;

	if (key < node->key)
		return Search(node->left, key);
	else
		return Search(node->right, key);
}

Node* BinarySearchTree::Search2(Node* node, int key)// 2. 무한 루프
{ // 성능적으로는 재귀함수보다 이방식이 좀 더 이득
	while (node && key != node->key)
	{
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return node;
}

Node* BinarySearchTree::Min(Node* node)
{
	while (node->left)
	{
		node = node->left;
	}

	return node;
}

Node* BinarySearchTree::Max(Node* node)
{
	while (node->right)
	{
		node = node->right;
	}
	return node;
}

Node* BinarySearchTree::Next(Node* node)
{
	if (node->right)
		return Min(node->right);

	Node* parent = node->parent;

	while (parent && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}
	return parent;
}

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	Node* node = _root;
	Node* parent = nullptr;

	while (node)
	{
		parent = node;
		if (key < node->key)
			node = node->left;
		else
			node = node->right;

	}

	newNode->parent = parent;

	if (key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;
}

void BinarySearchTree::Delete(int key)// 삭제는 로직이 복잡함.
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

void BinarySearchTree::Delete(Node* node)
{
	if (node == nullptr)
		return;

	if (node->left == nullptr)
		Replace(node, node->right);
	else if (node->right == nullptr)
		Replace(node, node->left);
	else
	{
		// 양쪽에 자식이 있을때

		// 다음 데이터 찾기
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}

}

// u 서브트리를 v 서브트리로 교체
// 그리고 delete u
void BinarySearchTree::Replace(Node* u, Node* v)
{
	// 위에서 아래쪽을 연결
	if (u->parent == nullptr)
		_root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;

	// 아래에서 위쪽을 연결
	if (v)
		v->parent = u->parent;

	delete u;
}
