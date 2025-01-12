#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    int n;
    cin >> n;
    stack<int> s;
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        while (!s.empty() && x > 0 && s.top() < 0)
        {
            s.pop();
        }

        if (x < 0 && !s.empty() && s.top()>0 && abs(x) < s.top()) continue;

        if (x < 0 && !s.empty() && s.top()>0 && abs(x) == s.top()) { s.pop(); continue; }

        while (!s.empty() && x < 0 && s.top()>0 && abs(x) > s.top())
        {
            s.pop();
        }

        if (s.empty() && x < 0) { res.push_back(x); continue; }

        if (!s.empty() && x < 0 && abs(x) < s.top())continue;

        s.push(x);

    }

    if (res.size() == 0)
    {
        cout << '\n'; return 0;
    }

    while (!s.empty())
    {
        res.push_back(s.top());
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }


}