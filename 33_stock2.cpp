https://www.codingninjas.com/codestudio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include<bits/stdc++.h>
// long solve(int ind,int operation,long *values,int n,vector<vector<long>>&dp)
// {
//     if(ind==n)
//     {
//         return 0;
//     }
//     if(dp[ind][operation]!=-1)
//         return dp[ind][operation];
    
//     long profit;
    
//     if(operation)
//     {
//         profit=max(-values[ind]+solve(ind+1,0,values,n,dp),solve(ind+1,1,values,n,dp));            
//     }
//     else
//         profit=max(values[ind]+solve(ind+1,1,values,n,dp),solve(ind+1,0,values,n,dp));
//     return dp[ind][operation]=profit;
                   
// }

// long solve(int n,long *values,vector<vector<long>>&dp)
// {
//     dp[n][0]=0,dp[n][1]=0;
//     for(int ind=n-1;ind>=0;ind--)
//     {
//         for(int op=0;op<=1;op++)
//         {
//             if(op)
//             {
//                 dp[ind][op]=max(-values[ind]+dp[ind+1][0],dp[ind+1][1]);            
//             }
//             else
//                 dp[ind][op]=max(values[ind]+dp[ind+1][1],dp[ind+1][0]);
//             }
//     }
    
//     return dp[0][1];
                   
// }

long solve(int n,long *values,vector<long>&dp)
{
    dp[0]=0,dp[1]=0;
    vector<long>curr(2,0);

    for(int ind=n-1;ind>=0;ind--)
    {
        for(int op=0;op<=1;op++)
        {
            long profit=0;
            if(op)
            {
                profit=max(-values[ind]+dp[0],dp[1]);            
            }
            else
            {
                profit=max(values[ind]+dp[1],dp[0]);
            }
            curr[op]=profit;
        }
        dp=curr;
        
    }
    
    return dp[1];
                   
}
long getMaximumProfit(long *values, int n)
{
    //Write your code here
    //1--Buy
    //0--Sell
//     vector<vector<long>>dp(n,vector<long>(2,-1));
//             return solve(0,1,values,n,dp);
   vector<long>dp(2,0);
    return solve(n,values,dp);
}