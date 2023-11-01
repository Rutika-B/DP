https://www.codingninjas.com/codestudio/problems/palindrome-partitioning_873266?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include<bits/stdc++.h>
bool ispalindrome(int i,int j,string s)
{
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
// int solve(int i,int n,string str,vector<int>&dp)
// {
//     if(i==n)
//         return 0;
//     if(dp[i]!=-1)
//         return dp[i];
//     int cost=INT_MAX,mini=INT_MAX;
//     for(int j=i;j<n;j++)
//     {
//         if(ispalindrome(i,j,str))
//         {
//             cost=1+solve(j+1,n,str,dp);
//         }
//         mini=min(cost,mini);
//     }
//     return dp[i]=mini;
// }

//--------------------------------------------------------------Tabulation-------------------------------------------------------
int solve(int n,string str)
{
    vector<int>dp(n+1,0);
    dp[n]=0;
    for(int i=n-1;i>=0;i--)
    {
            int cost=INT_MAX,mini=INT_MAX;
            for(int j=i;j<n;j++)
            {
                if(ispalindrome(i,j,str))
                {
                    cost=1+dp[j+1];
                }
                mini=min(cost,mini);
            }
            dp[i]=mini;
    }
    return dp[0];
}
int palindromePartitioning(string str) {
    // Write your code here
    int n=str.size();
//     vector<int>dp(n,-1);
//     return solve(0,n,str,dp)-1;
    return solve(n,str)-1;
}
