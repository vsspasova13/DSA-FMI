#include "UnionFind.h"
#include <queue>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Edge
{
	int from;
	int to;
	int weight;
};

vector<Edge> kruskal(int n, vector<Edge>& edges)
{
	sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
		return a.weight < b.weight;
		});
	UnionFind uf(n);
	vector<Edge> mst;
	for (int i = 0; i < edges.size(); i++)
	{
		if (uf.areInOneSet(edges[i].from, edges[i].to))
		{
			continue;
		}

		uf.unionVertices(edges[i].from, edges[i].to);
		mst.push_back(edges[i]);
		if (mst.size() == n - 1)
		{
			break;
		}
	}

	return mst;
}