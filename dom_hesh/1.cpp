#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Group
{
    int count;
    int start;
    int end;

    bool operator<(const Group& rhs)const
    {
        return start > rhs.start;
    }
};

int main() {

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int n, c;
        cin >> n >> c;

        priority_queue<Group> pq;
        vector<Group> gr;

        if (n == 0) { cout << 1 << endl; continue; }

        for (int j = 0; j < n; j++)
        {

            int k, x, y;
            cin >> k >> x >> y;
            gr.push_back({ k,x,y });


        }

        sort(gr.begin(), gr.end(), [](const Group& a, const Group& b) {
            return a.start < b.start;
            });

        int currTime = 0, currPeople = 0, index = 0;
        bool dali = false;

        while (index < n || !pq.empty())
        {

            while (index < n && gr[index].start <= currTime)
            {
                pq.push(gr[index]);
                index++;
            }

            if (pq.empty())
            {
                currTime++;
                continue;
            }

            while (!pq.empty() && pq.top().end < currTime)
            {
                currPeople -= pq.top().count;
                pq.pop();
            }

            if (currPeople + pq.top().count > c)
            {
                dali = true;
                break;
            }

            currPeople += pq.top().count;
            currTime = pq.top().start;
            pq.pop();
        }

        if (dali)cout << 0 << endl;
        else cout << 1 << endl;

    }


}