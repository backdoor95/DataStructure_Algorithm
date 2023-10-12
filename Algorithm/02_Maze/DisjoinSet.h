#pragma once
class DisjointSet
{
public:
	DisjointSet(int n) : _parent(n), _rank(n, 1)// _rank에서 n개를 1로 초기화
	{
		for (int i = 0; i < n; i++)
		{
			_parent[i] = i;
		}
	}

	// 니 대장이 누구니?
	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		return _parent[u] = Find(_parent[u]);
	}

	// u와 v를 합친다 (일단 u가 v 밑으로)
	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;

		if (_rank[u] > _rank[v])
			swap(u, v);

		// rank[u] <= rank[v] 보장됨.

		_parent[u] = v;

		// 조직 폭력배 구조?
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
