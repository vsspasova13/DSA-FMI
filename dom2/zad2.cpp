#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
sort(nums.begin(), nums.end());
    for (int i = 0; i < k; i++)
    {
        int f, s = 0;
        cin >> f >> s;

        auto upper = upper_bound(nums.begin(), nums.end(), s);
        auto low = lower_bound(nums.begin(), nums.end(), f);
       // if (upper == nums.end())
           // upper = nums.end()-1;
        cout << (upper - low) << endl;
    }


}
