https://www.codingninjas.com/codestudio/problems/house-robber_839733?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include <bits/stdc++.h>

long long int solve(vector<int> &nums)
{
    ///--------------------------------Space optimization-------------------------------
    int n=nums.size();
    long long int prev = nums[0];
    long long int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        long long int l = nums[i];
        if (i > 1)
        {
            l += prev2;
        }
        long long int r = prev;
        long long int curr = max(l, r);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    vector<int>tmp1,tmp2;
    int n=valueInHouse.size();
    if(n==1)return valueInHouse[0];
    for(int i=0;i<n;i++)
    {
        if(i!=0)tmp1.push_back(valueInHouse[i]);
        if(i!=n-1)tmp2.push_back(valueInHouse[i]);
    }
    long long int ans1=solve(tmp1);
    long long int ans2=solve(tmp2);
    return max(ans1,ans2);
    
}
