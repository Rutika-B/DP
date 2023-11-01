https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include<bits/stdc++.h>
// int solve(int i,int j,vector<int>&arr,vector<vector<int>>&dp)
// {
//     if(i==j)
//     {
//         return 0;
//     }
//     if(dp[i][j]!=-1)return dp[i][j];
//     int mini=1e9;
//     for(int k=i;k<j;k++)
//     {
//         int step=arr[i-1]*arr[k]*arr[j]+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
//         mini=min(step,mini);
//     }
//     return dp[i][j]=mini;
// }

int solve(int n,vector<int>&arr,vector<vector<int>>&dp)
{
    
    for(int i=1;i<n;i++)//base case
    {
        dp[i][i]=0;
    }
   
    for(int i=n-1;i>=1;i--)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            int mini=1e9;
            for(int k=i;k<j;k++)
            {
                int step=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                mini=min(step,mini);
            }
            dp[i][j]=mini;
        }
    }
    
    return dp[1][n-1];
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
//     vector<vector<int>>dp(N,vector<int>(N,-1));
//     return solve(1,N-1,arr,dp);
    vector<vector<int>>dp(N,vector<int>(N,0));
    return solve(N,arr,dp);
}