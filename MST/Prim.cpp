#include <queue>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Edge
{
	int from;
	int to;
	int weight;

	bool operator<(const Edge& rhs)const
	{
		return weight > rhs.weight;
	}
};

vector<Edge> prim(int n, int start, unordered_map<int, vector<Edge>>& graph)
{
	priority_queue<Edge> pq;
	unordered_set<int> visited;
	pq.push({ start,start,0 });

	vector<Edge> mst;

	while (!pq.empty() && visited.size() < n)
	{
		auto curr = pq.top();
		pq.pop();

		if (visited.count(curr.to)) //ako e poseten skipvame go
		{
			continue;
		}

		visited.insert(curr.to);
		mst.push_back(curr);

		for (auto& ed : graph[curr.to])
		{
			if (visited.count(ed.to))
			{
				continue;
			}

			pq.push(ed);
		}
	}

	return mst;

}

int test(int n, unordered_map<int,vector<Edge>>& graph)
{
	auto mst = prim(n, 1, graph);
	if (mst.size() - 1 < n - 1)
	{
		return -1;
	}

	int res = 0;
	for (int i = 1; i < mst.size(); i++)
	{
		res += mst[i].weight;
	}

	return res;
}

int prim2(int n, int start, unordered_map<int, vector<Edge>>& graph)
{
	priority_queue<Edge> pq;
	unordered_set<int> visited;
	pq.push({ start,start,0 });

	int totalWeight = 0;

	while (!pq.empty() && visited.size() < n)
	{
		auto curr = pq.top();
		pq.pop();

		if (visited.count(curr.to))
		{
			continue;
		}

		visited.insert(curr.to);
		totalWeight += curr.weight;

		for (auto& ed : graph[curr.to])
		{
			if (visited.count(ed.to))
			{
				continue;
			}
			pq.push(ed);
		}

	}

	return totalWeight;
}