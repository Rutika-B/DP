https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h> 
// int solve(int i,int j,vector<vector<int>>&dp)
// int solve(int m,int n,vector<vector<int>>&dp)
int solve(int m,int n,vector<int>&dp)
{
//     if(i==0 && j==0)
//     {
//         return 1;
//     }
//     if(i<0 || j<0)
//     {
//         return 0;
//     }
//     int up=solve(i-1,j);
//     int left=solve(i,j-1);
//     return up+left;
    
//-----------------------------------------------Memoization---------------------------------------------------
//     if(i==0 && j==0)
//     {
//         return 1;
//     }
//     if(i<0 || j<0)
//     {
//         return 0;
//     }
//     if(dp[i][j]!=-1)
//     {
//         return dp[i][j];
//     }
//     int up=solve(i-1,j,dp);
//     int left=solve(i,j-1,dp);
//     return dp[i][j]=up+left;
    
    //------------------------------------------Tabulation----------------------------------------------------------
//     for(int i=0;i<=m;i++)
//     {
//         for(int j=0;j<=n;j++)
//         {
//             if(i==0 && j==0)
//             {
//                 dp[i][j]=1;
//                 continue;
//             }
//             int up=0,left=0;
//             if(i>0)
//             {
//                 up=dp[i-1][j];
//             }
//             if(j>0)
//             {
//                 left=dp[i][j-1];
//             }
//             dp[i][j]=up+left;
//         }
//     }
//     return dp[m][n];
    
    //----------------------------------Space optimization--------------------------------------------------
     for(int i=0;i<=m;i++)
    {
         vector<int>tmp(n+1,0);
        for(int j=0;j<=n;j++)
        {
            if(i==0 && j==0)
            {
                tmp[j]=1;
                continue;
            }
            int up=0,left=0;
            if(i>0)
            {
                up=dp[j];
            }
            if(j>0)
            {
                left=tmp[j-1];
            }
            tmp[j]=left+up;
        }
         dp=tmp;
    }
    return dp[n];
}
int uniquePaths(int m, int n) {
	// Write your code here.
//     vector<vector<int>>dp(m,vector<int>(n,-1));
    vector<int>dp(n,-1);
    return solve(m-1,n-1,dp);
}