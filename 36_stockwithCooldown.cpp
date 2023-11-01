https://www.codingninjas.com/codestudio/problems/highway-billboards_3125969?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include<bits/stdc++.h>
// int solve(int ind,int operation,vector<int>&values,int n,vector<vector<int>>&dp)
// {
//     if(ind>=n)
//     {
//         return 0;
//     }
//     if(dp[ind][operation]!=-1)return dp[ind][operation];
    
//     int profit;
    
//     if(operation)
//     {
       
//              profit=max(-values[ind]+solve(ind+1,0,values,n,dp),solve(ind+1,1,values,n,dp));   
       
//     }
//     else
//     {
//         profit=max(values[ind]+solve(ind+2,1,values,n,dp),solve(ind+1,0,values,n,dp));
// //                                      ^
// //                                      |
// //                                      |
// //                                      cooldown condition(you can not buy right after sell,that's why we will directly move to nextdayafter)
//     }
//     return dp[ind][operation]=profit;
                   
// }


// int solve(vector<int>&values,int n,vector<vector<int>>&dp)
// {
//     for(int ind=n-1;ind>=0;ind--)
//     {
//         for(int op=0;op<=1;op++)
//         {
//                 int profit;
//                 if(op)
//                 {
//                      profit=max(-values[ind]+dp[ind+1][0],dp[ind+1][1]);   
//                 }
//                 else
//                 {
//                     profit=max(values[ind]+dp[ind+2][1],dp[ind+1][0]);
//                 }
//             dp[ind][op]=profit;
//         }
//     }
//     return dp[0][1];         
// }

//------------------------------------Space optimization---------------------------------------
int solve(vector<int>&values,int n)
{
    vector<int>cur(2,0);
    vector<int>front1(2,0);
    vector<int>front2(2,0);
    
    for(int ind=n-1;ind>=0;ind--)
    {
        cur[1]=max(-values[ind]+front1[0],front1[1]);   
        cur[0]=max(values[ind]+front2[1],front1[0]);
        front2=front1;
        front1=cur;        
    }
    return cur[1];         
}
int stockProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
//     vector<vector<int>>dp(n,vector<int>(2,-1));
//     return solve(0,1,prices,n,dp);
//         vector<vector<int>>dp(n+2,vector<int>(3,0));
//     return solve(prices,n,dp);
    return solve(prices,n);
}