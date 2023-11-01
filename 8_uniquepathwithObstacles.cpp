https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include <bits/stdc++.h> 
int mod=(int)(1e9+7);
//--------------------------------------Recursion---------------------------------------------------------------
// int solve(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp)
// int solve(int m,int n,vector<vector<int>>&mat,vector<vector<int>>&dp)
int solve(int m,int n,vector<vector<int>>&mat,vector<int>&dp)
{
//     if(i<0 || j<0)
//     {
//         return 0;
//     }
//     if(mat[i][j]==-1)  //No path through obstacles
//     {
//         return 0;
//     }
//     if(i==0 && j==0)
//     {
//         return 1;
//     }
   
//     int up=solve(i-1,j,mat,dp);
//     int left=solve(i,j-1,mat,dp);
//     return up+left;
    
    //--------------------------------Memoization-----------------------------------------------------------------
    
//     if(i<0 || j<0)
//     {
//         return 0;
//     }
//     if(mat[i][j]==-1)
//     {
//         return 0;
//     }
//     if(i==0 && j==0)
//     {
//         return 1;
//     }
//     if(dp[i][j]!=-1)
//     {
//         return dp[i][j];
//     }
//     int up=solve(i-1,j,mat,dp);
//     int left=solve(i,j-1,mat,dp);
//     return dp[i][j]=up+left;
    

    //-------------------------------Tabulation--------------------------------------------------------------
    
//     for(int i=0;i<=m;i++)
//     {
//         for(int j=0;j<=n;j++)
//         {
//             if(mat[i][j]==-1)
//             {
//                 dp[i][j]=0;
//                 continue;
//             }
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
//             dp[i][j]=(up+left)%mod;
//         }
//     }
//     return dp[m][n];
    
    //-----------------------------------------Space optimization--------------------------------------
    for(int i=0;i<=m;i++)
    {
        vector<int>tmp(n+1,0);
        for(int j=0;j<=n;j++)
        {
            if(mat[i][j]==-1){
                tmp[j]=0;
                continue;
            }
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
            tmp[j]=(up+left)%mod;
        }
        dp=tmp;
    }
    return dp[n];
    
    
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
//     vector<vector<int>>dp(n,vector<int>(m,-1));
    vector<int>dp(m,0);
    return solve(n-1,m-1,mat,dp);
}