https://www.codingninjas.com/codestudio/problems/edit-distance_630420?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include<bits/stdc++.h>
int solve(int i,int j,string s,string t,vector<vector<int>>&dp)
{
    if(i<0 && j<0)return 0;
    if(i<0)return j+1;
    if(j<0)return i+1;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j])
        return dp[i][j]=solve(i-1,j-1,s,t,dp);
    else
        return dp[i][j]=1+min(solve(i,j-1,s,t,dp),min(solve(i-1,j-1,s,t,dp),solve(i-1,j,s,t,dp)));//choos min among insertion,deletion,replacement operations
    
}


// int solve(int n,int m,string s,string t,vector<vector<int>>&dp)
// {
//     for(int i=0;i<=n;i++)
//     {
//         dp[i][0]=i;
// //     }
// //     for(int i=0;i<=m;i++)
// //     {
// //         dp[0][i]=i;
// //     }
// //     for(int i=1;i<=n;i++)
// //     {
// //         for(int j=1;j<=m;j++)
// //         {
// //             if(s[i-1]==t[j-1])
// //             {
// //                 dp[i][j]=dp[i-1][j-1];
// //             }
// //             else
// //             {
// //                 dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
// //             }
// //         }
// //     }
// //     return dp[n][m];
// // }


// int solve(int n,int m,string s,string t,vector<int>&dp)
// {
//     for(int i=0;i<=m;i++)
//     {
//         dp[i]=i;
//     }
//     vector<int>tmp(m+1,0);
//     for(int i=1;i<=n;i++)
//     {
//         tmp[0]=i;
//         for(int j=1;j<=m;j++)
//         {
//             if(s[i-1]==t[j-1])
//             {
//                 tmp[j]=dp[j-1];
//             }
//             else
//             {
//                 tmp[j]=1+min(tmp[j-1],min(dp[j-1],dp[j]));
//             }
//         }
//         dp=tmp;
//     }
//     return dp[m];
// }
int editDistance(string str1, string str2)
{
    //write you code here
    int l1=str1.length();
    int l2=str2.length();
    vector<vector<int>>dp(l1,vector<int>(l2,-1));
    return solve(l1-1,l2-1,str1,str2,dp);
//         vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
//     vector<int>dp(l2+1,0);
//     return  solve(l1,l2,str1,str2,dp);
}