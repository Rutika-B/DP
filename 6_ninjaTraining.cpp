https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include <bits/stdc++.h>
// int solve(int n,int prev,vector<vector<int>>&points,vector<vector<int>>&dp)
//  int solve(int n,vector<vector<int>>&points,vector<vector<int>>&dp)
 int solve(int n,vector<vector<int>>&points,vector<int>&dp)
{
//     if(n==0)
//     {
//         int ans=0;
//         for(int i=0;i<3;i++)
//         {
//             if(prev!=i)
//             {
//                 ans=max(ans,points[n][i]);
//             }
//         }
//         return ans;
//     }
//     int ans=0;
//     for(int i=0;i<3;i++)
//     {
//         if(prev!=i)
//         {           
//             int sum=points[n][i]+solve(n-1,i,points);
//             ans=max(ans,sum);
//         }
//     }
//     return ans;
    
//     -----------------------------------------------------------Memoization----------------------------------------------
    
//     if(dp[n][prev]!=-1)
//     {
//         return dp[n][prev];
//     }
//     if(n==0)
//     {
//         int ans=0;
//         for(int i=0;i<3;i++)
//         {
//             if(prev!=i)
//             {
//                 ans=max(ans,points[n][i]);
//             }
//         }
//         return dp[n][prev]=ans;
//     }
//     int ans=0;
//     for(int i=0;i<3;i++)
//     {
//         if(prev!=i)
//         {           
//             int sum=points[n][i]+solve(n-1,i,points,dp);
//             ans=max(ans,sum);
//         }
//     }
//     return dp[n][prev]=ans;
    
    
    //-----------------------------------Tabulation-----------------------------------------------------------------
//     for(int prev=0;prev<3;prev++)
//     {
//         int ans=0;
//         for(int task=0;task<3;task++)
//         {
//             if(prev!=task)
//             {
//                 ans=max(ans,points[0][task]);
//             }
//         }
//         dp[0][prev]=ans;
//     }
    
//     for(int day=1;day<=n;day++)
//     {
//         for(int prev=0;prev<3;prev++)
//         {
//             int ans=0;
//             for(int task=0;task<3;task++)
//             {
//                 if(prev!=task)
//                 {
//                     int sum=points[day][task]+dp[day-1][task];
//                     ans=max(sum,ans);
//                 }
//             }
//             dp[day][prev]=ans;
//         }
//     }
//     int fans=0;
//     for(int i=0;i<3;i++)
//     {
//         fans=max(fans,dp[n][i]);
//     }
//     return fans;
     
     
     
     //--------------------------------Space optimization------------------------------------
     dp[0]=max(points[0][1],points[0][2]);
     dp[1]=max(points[0][0],points[0][2]);
     dp[2]=max(points[0][1],points[0][0]);
    
    for(int day=1;day<=n;day++)
    {
        vector<int>tmp(3);
        for(int prev=0;prev<3;prev++)
        {
            int ans=0;
            for(int task=0;task<3;task++)
            {
                if(prev!=task)
                {
                    int sum=points[day][task]+dp[task];
                    ans=max(sum,ans);
                }
            }
            tmp[prev]=ans;
        }
        dp=tmp;
    }
    int fans=0;
    for(int i=0;i<3;i++)
    {
        fans=max(fans,dp[i]);
    }
    return fans;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
   
//     vector<vector<int>>dp(n,vector<int>(4,-1));
//     return solve(n-1,3,points,dp);
    vector<int>dp(n,0);
    return solve(n-1,points,dp);
}








