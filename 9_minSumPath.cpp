https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include<bits/stdc++.h>
// int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp)
// int solve(int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp)
int solve(int n,int m,vector<vector<int>>&grid,vector<int>&dp)
{
//     if(i==0 && j==0)return grid[i][j];
//     if(i<0 || j<0)return 1e9;
//     int up=grid[i][j]+solve(i-1,j,grid);
//     int left=grid[i][j]+solve(i,j-1,grid);
//     return min(up,left);
   
    
    
//     if(i==0 && j==0)return grid[i][j];
//     if(i<0 || j<0)return 1e9;
//      if(dp[i][j]!=-1)return dp[i][j];
//     int up=grid[i][j]+solve(i-1,j,grid,dp);
//     int left=grid[i][j]+solve(i,j-1,grid,dp);
//     return dp[i][j]=min(up,left);
    
    
    
//     for(int i=0;i<=n;i++)
//     {
//         for(int j=0;j<=m;j++)
//         {
//             if(i==0 && j==0)
//             {    
//                 dp[i][j]=grid[0][0];
//                 continue;
//             }
//             int up=1e9,left=1e9;
//             if(i>0)
//             {
//                 up=grid[i][j]+dp[i-1][j];
//             }
//             if(j>0)
//             {
//                 left=grid[i][j]+dp[i][j-1];
//             }
//             dp[i][j]=min(up,left);
//         }
//     }
//     return dp[n][m];
    
    
    
    
    for(int i=0;i<=n;i++)
    {
        vector<int>tmp(m+1,0);
        for(int j=0;j<=m;j++)
        {
            if(i==0 && j==0)
            {    
                tmp[j]=grid[0][0];
                continue;
            }
            int up=1e9,left=1e9;
            if(i>0)
            {
                up=grid[i][j]+dp[j];
            }
            if(j>0)
            {
                left=grid[i][j]+tmp[j-1];
            }
            tmp[j]=min(up,left);
        }
        dp=tmp;
    }
    return dp[m];
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size();
    int m=grid[0].size();
//     vector<vector<int>>dp(n,vector<int>(m,-1));
    vector<int>dp(m,0);
    return solve(n-1,m-1,grid,dp);
}