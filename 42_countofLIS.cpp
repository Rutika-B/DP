https://www.codingninjas.com/codestudio/problems/number-of-longest-increasing-subsequence_3751627?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include<bits/stdc++.h>
int findNumberOfLIS(vector<int> &arr)
{
    // Write your code here.
    int n=arr.size();
    vector<int>dp(n,1);
    vector<int>count(n,1);
    int maxdp=1,maxcount=0;
    for(int i=1;i<n;i++)
    {
        for(int prev=0;prev<i;prev++)
        {
            if(arr[i]>arr[prev])
            {
                if(dp[i]<dp[prev]+1)
                {
                    dp[i]=dp[prev]+1;
                    count[i]=count[prev];
                }
                else if(dp[i]==dp[prev]+1)
                {
                    count[i]+=count[prev];
                }
            }
        }
        if(maxdp<dp[i])
        {
            maxdp=dp[i]; 
        }
    }
    for(int i=0;i<n;i++)
    {
        if(dp[i]==maxdp)
        {
            maxcount+=count[i];
        }
    }
    return maxcount;
}