#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool canPartition(vector< long long > nums, long long  k, long long maxNum)
{
    long long curr = 0;
    long long groups = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        curr += nums[i];
        if (curr > maxNum)
        {
            groups++;
            curr = nums[i];
        }
        if (groups > k)
            return false;
    }
    return true;

}

int maxMinSum(vector< long long > nums, long long  k)
{
    long long maxSum = 0, maxNum = nums[0];

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > maxNum)maxNum = nums[i];
        maxSum += nums[i];
    }

    long long  l = maxNum, r = maxSum;
    long long  mid = 0;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if (canPartition(nums, k, mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}


void nzzzzz(){
    long long  n, k;
    cin >> n >> k;
    vector< long long > nums(n);
    for (int i = 0; i < n; i++)
    {
        long long  x;
        cin >> x;
        nums[i] = x;
    }
    cout << maxMinSum(nums, k);
}


