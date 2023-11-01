https://www.codingninjas.com/codestudio/problems/rahul-and-his-chocolates_3118974?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include<bits/stdc++.h>
int solve(int ind,int operation,vector<int>&values,int fee,int n,vector<vector<int>>&dp)
{
    if(ind==n)
    {
        return 0;
    }
    if(dp[ind][operation]!=-1)
        return dp[ind][operation];
    
    int profit;
    
    if(operation)
    {
        profit=max(-values[ind]+solve(ind+1,0,values,fee,n,dp),solve(ind+1,1,values,fee,n,dp));            
    }
    else
        profit=max(values[ind]-fee+solve(ind+1,1,values,fee,n,dp),solve(ind+1,0,values,fee,n,dp));
    return dp[ind][operation]=profit;
                   
}
int maximumProfit(int n, int fee, vector<int> &prices) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return solve(0,1,prices,fee,n,dp);
}
