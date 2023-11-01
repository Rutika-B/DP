https://www.codingninjas.com/codestudio/problems/subsequence-counting_3755256?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
#include<bits/stdc++.h>
int mod=1e9+7;
// int solve(int i,int j,string t,string s,vector<vector<int>>&dp)
// {
//     if(j<0)
//         return 1;
//     if(i<0)
//         return 0;
//     if(dp[i][j]!=-1)return dp[i][j];
//     if(t[i]==s[j])
//         return dp[i][j]=(solve(i-1,j-1,t,s,dp)+solve(i-1,j,t,s,dp))%mod;
//     else
//         return dp[i][j]=solve(i-1,j,t,s,dp)%mod;
// }

// int solve(int n,int m,string t,string s,vector<vector<int>>&dp)
// {
//     for(int i=0;i<=n;i++)
//     {
//         dp[i][0]=1;
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             if(t[i-1]==s[j-1])
//             {
//                 dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
//             }
//             else
//             {
//                 dp[i][j]=dp[i-1][j]%mod;
//             }
//         }
//     }
//     return dp[n][m];
// }
int solve(int n,int m,string t,string s,vector<int>&dp)
{
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        
        for(int j=m;j>=1;j--)
        {
            if(t[i-1]==s[j-1])
            {
                dp[j]=(dp[j-1]+dp[j])%mod;
            }
            else
            {
                dp[j]=dp[j]%mod;
            }
        }
    }
    return dp[m];
}
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    // Write your code here.
//     vector<vector<int>>dp(lt,vector<int>(ls,-1));
      //     return solve(lt-1,ls-1,t,s,dp);
    vector<int>dp(ls+1,0);
    return solve(lt,ls,t,s,dp);
} 