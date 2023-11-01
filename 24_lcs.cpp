https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>
// int solve(int i,int j,string s,string t,vector<vector<int>>&dp)
// {
//     if(i<0 || j<0)
//         return 0;
//     if(dp[i][j]!=-1)return dp[i][j];
//     if(s[i]==t[j])
//         return dp[i][j]=1+solve(i-1,j-1,s,t,dp);
//     else
//         return dp[i][j]=0+max(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));
// }
int solve(int l1,int l2,string s,string t,vector<vector<int>>&dp)
{

    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[l1][l2];
}

// int solve(int l1,int l2,string s,string t,vector<int>&dp)
// {
//     vector<int>tmp(l2+1,0);
//     for(int i=1;i<=l1;i++)
//     {
//         for(int j=1;j<=l2;j++)
//         {
//             if(s[i-1]==t[j-1])
//             {
//                 tmp[j]=1+dp[j-1];
//             }
//             else
//             {
//                 tmp[j]=max(dp[j],tmp[j-1]);
//             }
//         }
//         dp=tmp;
//     }
//     return dp[l2];
   
// }
int lcs(string s, string t)
{
	//Write your code here
    int l1=s.length();
    int l2=t.length();
//     vector<vector<int>>dp(l1+1,vector<int>(l2+1,-1));
    vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
//         vector<int>dp(l2+1,0);
    int ans=solve(l1,l2,s,t,dp);
    
    ///-----------------------to print such subsequence
     int i=l1,j=l2;
    stack<char>ctnr;
    while(i>0||j>0)
    {
        if(s[i-1]==t[j-1])
        {
            ctnr.push(s[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }   
                                  
    }
    
    while(!ctnr.empty())
    {
        char c=ctnr.top();
//         cout<<c;
        ctnr.pop();
    }
//     cout<<endl;
    
    return ans;
}