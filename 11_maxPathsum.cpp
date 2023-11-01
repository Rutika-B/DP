https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
#include <bits/stdc++.h>
// int solve(int i,int j,vector<vector<int>>&a,int m,vector<vector<int>>&dp)
// int solve(int n,int m,vector<vector<int>>&a,vector<vector<int>>&dp)
int solve(int n,int m,vector<vector<int>>&a,vector<int>&dp)
{
//     if(j<0 || j>=m)return -1e9;
//     if(i==0)
//     {
//         return a[i][j];
//     }
//     if(dp[i][j]!=-1)return dp[i][j];
//     int left=a[i][j]+solve(i-1,j-1,a,m,dp);
//     int up=a[i][j]+solve(i-1,j,a,m,dp);
//     int rit=a[i][j]+solve(i-1,j+1,a,m,dp);
//     return dp[i][j]=max(left,max(up,rit));
    
    
    
    
//     for(int i=0;i<=m;i++)
//     {
//         dp[0][i]=a[0][i];
//     }
//     for(int i=1;i<=n;i++)
//     {
//        for(int j=0;j<=m;j++)
//        {
//            int l=-1e9,r=-1e9;
//            if(j!=0)
//            {
//                l=dp[i-1][j-1];
//            }
//            if(j!=m)
//            {
//                r=dp[i-1][j+1];
//            }
//            int up=dp[i-1][j];
//            dp[i][j]=a[i][j]+max(up,max(l,r));
//        }
//     }
//     return dp[n][m];
    
    
    
    for(int i=0;i<=m;i++)
    {
        dp[i]=a[0][i];
    }
    for(int i=1;i<=n;i++)
    {
        vector<int>tmp(m+1,0);
       for(int j=0;j<=m;j++)
       {
           int l=-1e9,r=-1e9;
           if(j!=0)
           {
               l=dp[j-1];
           }
           if(j!=m)
           {
               r=dp[j+1];
           }
           int up=dp[j];
           tmp[j]=a[i][j]+max(up,max(l,r));
       }
        dp=tmp;
    }
     return dp[m];
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int ans=-1e9;
//     vector<vector<int>>dp(n,vector<int>(m,-1));
//     for(int i=0;i<m;i++)//Memoization
//     {
//         ans=max(ans,solve(n-1,i,matrix,m,dp));
//     }
    vector<int>dp(m,-1);
    solve(n-1,m-1,matrix,dp);
    for(int i=0;i<m;i++)
    {
        ans=max(ans,dp[i]);
    }
    return ans;
}






