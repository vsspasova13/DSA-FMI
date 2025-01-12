#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int recc(int ind, int d, int start, int end)
{
    if (start > end) return -1;

    int size = end - start + 1;
    int mid1 = start + (end - start) / 3;
    int mid2 = end - (end - start) / 3;

    if (size == 1) {
        if (start == ind)return d;
        else return -1;
    }


    if (ind > mid1 && ind < mid2)
    {
        return d;
    }


    d++;

   

    if (ind <= mid1) return recc(ind, d, start, mid1);
    //else if (ind <= mid1 && mid1 > 0) res1 = recc(ind, d, start, mid1);
    else if (ind >= mid2)  return recc(ind, d, mid2, end);


    return -1;
}


void oook(){

    int n, p;
    cin >> p >> n;
    int size = pow(3, p);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        cout << recc(x, 1, 0, size - 1) << endl;
    }

}
