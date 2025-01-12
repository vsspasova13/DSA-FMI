#include <vector>
#include <algorithm>

using namespace std;

class UnionFind
{
	vector<int> parents;
	vector<int> sizes;

	int findParent(int v)
	{
		if (parents[v] == v)
		{
			return v;
		}

		return parents[v] = findParent(parents[v]);
	}

public:
	UnionFind(int n) : parents(n), sizes(n)
	{
		for (int i = 0; i < n; i++)
		{
			parents[i] = i;
			sizes[i] = 1;
		}
	}

	bool areInOneSet(int u, int v)
	{
		return findParent(u) == findParent(v);
	}

	void unite(int u, int v)
	{
		int p1 = findParent(u);
		int p2 = findParent(v);

		if (p1 == p2)return;

		if (sizes[p1] > sizes[p2])
		{
			swap(p1, p2);
		}

		sizes[p2] += sizes[p1];
		parents[p1] = p2;
	}
};

class Solution {
public:
	int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {

		for (int i = 1; i <= n; i++)
		{
			pipes.push_back({0, i, wells[i - 1]});
		}

		UnionFind uf(n + 1);
		sort(pipes.begin(), pipes.end(), [](const vector<int>& a, const vector<int>& b) {
			return a[2] < b[2];
			});
		int comp = n + 1;
		int res = 0;

		for (int i = 0; i < pipes.size(); i++)
		{
			if (uf.areInOneSet(pipes[i][0], pipes[i][1]))
			{
				continue;
			}

			uf.unite(pipes[i][0], pipes[i][1]);
			res += pipes[i][2];
			comp--;
			if (comp == 1) break;
		}

		return res;
	}
};