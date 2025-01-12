#include <vector>
#include <iostream>
using namespace std;

struct Edge
{
	int from, to, weight;
};

vector<int> bellman_ford(int s, int n, const vector<Edge>& edges)
{
	vector<int> distances(n, INT_MAX);
	distances[s] = 0;

	for (int i = 0; i < n - 1; i++)
	{
		for (const auto& e : edges)
		{
			if (distances[e.from] != INT_MAX)
			{
				distances[e.to] = min(distances[e.from] + e.weight, distances[e.to]);
			}
		}
	}

	for (const auto& e : edges)
	{
		if (distances[e.from] != INT_MAX)
		{
			if (distances[e.from] + e.weight < distances[e.to])
			{
				throw std::logic_error("Negative cycle");
			}
		}
	}

	return distances;
}
