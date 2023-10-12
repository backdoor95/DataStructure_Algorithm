#pragma once
class DisjointSet
{
public:
	DisjointSet(int n) : _parent(n), _rank(n, 1)// _rank���� n���� 1�� �ʱ�ȭ
	{
		for (int i = 0; i < n; i++)
		{
			_parent[i] = i;
		}
	}

	// �� ������ ������?
	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		return _parent[u] = Find(_parent[u]);
	}

	// u�� v�� ��ģ�� (�ϴ� u�� v ������)
	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;

		if (_rank[u] > _rank[v])
			swap(u, v);

		// rank[u] <= rank[v] �����.

		_parent[u] = v;

		// ���� ���¹� ����?
		// [1]			[3]
		// [2]		[4] [5] [1]
		// [6]			[0] [2]
		//					[6]
		if (_rank[u] == _rank[v])
			_rank[v]++;


	}

private:
	vector<int> _parent;
	vector<int> _rank;

};
