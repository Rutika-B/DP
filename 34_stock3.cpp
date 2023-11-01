https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
#include<bits/stdc++.h>
// int solve(int ind,int operation,int cap,vector<int>&prices,int n,vector<vector<vector<int>>>&dp)
// {
//     if(cap==0)
//         return 0;
//     if(ind==n)
//     {
//         return 0;
//     }
//     if(dp[ind][operation][cap]!=-1)return dp[ind][operation][cap];
//     int profit;
//     if(operation)
//     {
//         profit=max(-prices[ind]+solve(ind+1,0,cap,prices,n,dp),solve(ind+1,1,cap,prices,n,dp));
//     }
//     else
//     {
//         profit=max(prices[ind]+solve(ind+1,1,cap-1,prices,n,dp),solve(ind+1,0,cap,prices,n,dp));
//     }
//     return dp[ind][operation][cap]=profit;
// }



// -----------------------------------------Tabulation--------------------------------------
    
    
    
    
// int solve(int n,vector<int>&prices,vector<vector<vector<int>>>&dp)
// {

// //      if(cap==0)
// //         return 0;
//     //When cap == 0, the other two variables: ind and cap can take any value, therefore we can set the following two loops and set dp[ind][buy][0] = 0.
    
//     for(int ind=0;ind<=n;ind++)
//         for(int operation=0;operation<=1;operation++)
//             dp[ind][operation][0]=0;
    
// //     if(ind==n)
// //     {
// //         return 0;
// //     }
//     //When ind == n, the other two variables: cap and buy can take any value, therefore we can set the following two loops and set dp[n][operations][cap] = 0

//     for(int operation=0;operation<=1;operation++)
//         for(int cap=0;cap<=2;cap++)
//                dp[n][operation][cap]=0;
    
//     for(int ind=n-1;ind>=0;ind--)
//     {
//         for(int op=0;op<=1;op++)
//         {
//             for(int cap=1;cap<=2;cap++)
//             {
//                 int profit;
//                     if(op)
//                     {
//                         profit=max(-prices[ind]+dp[ind+1][0][cap], dp[ind+1][1][cap]);
//                     }
//                     else
//                     {
//                         profit=max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
//                     }
//                 dp[ind][op][cap]=profit;
//             }
//         }
//     }



//     return dp[0][1][2];
// }


// --------------------------------------------Space optimization----------------------------------------


int solve(int n,vector<int>&prices,vector<vector<int>>&dp)
{    
    vector<vector<int>>curr(2,vector<int>(3,0));
      
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int op=0;op<=1;op++)
        {
            for(int cap=1;cap<=2;cap++)
            {
              
                    if(op)
                    {
                        curr[op][cap]=max(-prices[ind]+dp[0][cap], dp[1][cap]);
                    }
                    else
                    {
                        curr[op][cap]=max(prices[ind]+dp[1][cap-1],dp[0][cap]);
                    }
                
            }
        }
        dp=curr;
    }
    
    return dp[1][2];
}
int maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
//     vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
//     return solve(0,1,2,prices,n,dp);
    
//         vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,0)));
//     return solve(n,prices,dp);
    
    
    vector<vector<int>>dp(2,vector<int>(3,0));
    return solve(n,prices,dp);
}