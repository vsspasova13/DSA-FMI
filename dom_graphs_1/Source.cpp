#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<int, unordered_set<int>> graph;
int minPath = INT_MAX;

void bfs(int curr, unordered_map<int, unordered_set<int>>& graph, int& path, unordered_set<int>& gr, unordered_set<int>& visited)
{
    if (!gr.count(curr)) return;

    int dist = 0;
    queue<int> q;
    q.push(curr);
    visited.insert(curr);

    while (!q.empty())
    {
        int level = q.size();
      
        if (dist < path && dist != 0)path = dist;

        for (int i = 0; i < level; i++)
        {
            int cur = q.front();
            q.pop();

            for (int neigh : graph[cur])
            {
               
                if (!visited.count(neigh))
                {   
                    if (!gr.count(neigh)) continue;
                    visited.insert(neigh);
                    q.push(neigh);

                }
            }
        }
        dist++;
    }

}

int main() {

    int v, e;
    cin >> v >> e;

    for (int i = 1; i <= v; i++)
    {
        graph[v];
    }

    int c1, c2;
    for (int i = 0; i < e; i++)
    {
        cin >> c1 >> c2;
        graph[c1].insert(c2);
        graph[c2].insert(c1);
    }

    vector<int> groups(v+1, 0);
    for (int i = 1; i <= v; i++)
    {
        cin >> groups[i];
    }

    int myGr; cin >> myGr;
    unordered_set<int> group;
    for (int i = 1; i <= v; i++)
    {
        if (groups[i] == myGr)group.insert(i);
    }
    unordered_set<int> visited;
    for (auto it = graph.cbegin(); it != graph.cend(); it++)
    {
        if (!visited.count(it->first))
        {
            bfs(it->first, graph, minPath, group, visited);
        }
    }

    cout << minPath;

}
