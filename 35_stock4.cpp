https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_1080698?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include<bits/stdc++.h>
// int solve(int ind,int noftransaction,int n,vector<int>&prices,int k,vector<vector<int>>&dp)
// {
//     if(ind==n || noftransaction==2*k)
//     {
//         return 0;
//     }
//     if(dp[ind][noftransaction]!=-1)return dp[ind][noftransaction];
//     int profit;
//     if(noftransaction%2==0)
//     {
//         profit=max(-prices[ind]+solve(ind+1,noftransaction+1,n,prices,k,dp),solve(ind+1,noftransaction,n,prices,k,dp));
//     }
//     else
//     {
//         profit=max(prices[ind]+solve(ind+1,noftransaction+1,n,prices,k,dp),solve(ind+1,noftransaction,n,prices,k,dp));
//     }
//     return dp[ind][noftransaction]=profit;
// }

// int solve(int n,vector<int>&prices,int k,vector<vector<int>>&dp)
// {
   
//     for(int ind=n-1;ind>=0;ind--)
//     {
//         for(int noftransaction=2*k-1;noftransaction>=0;noftransaction--)
//         {
//             if(noftransaction%2==0)
//             {
//                 dp[ind][noftransaction]=max(-prices[ind]+dp[ind+1][noftransaction+1],dp[ind+1][noftransaction]);
//             }
//             else
//             {
//                dp[ind][noftransaction]=max(prices[ind]+dp[ind+1][noftransaction+1],dp[ind+1][noftransaction]);
//             }
//         }
//     }
    
//    return dp[0][0];
// }


int solve(int n,vector<int>&prices,int k,vector<int>&dp)
{
   vector<int>curr(2*k+1,0);
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int noftransaction=2*k-1;noftransaction>=0;noftransaction--)
        {
            if(noftransaction%2==0)
            {
                curr[noftransaction]=max(-prices[ind]+dp[noftransaction+1],dp[noftransaction]);
            }
            else
            {
               curr[noftransaction]=max(prices[ind]+dp[noftransaction+1],dp[noftransaction]);
            }
        }
        dp=curr;
    }
    
   return dp[0];
}
int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
//     vector<vector<int>>dp(n+1,vector<int>(2*k+1,-1));
//     return solve(0,0,n,prices,k,dp);
    vector<int>dp(2*k+1,0);
    return solve(n,prices,k,dp);
}
