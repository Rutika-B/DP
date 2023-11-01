https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include <bits/stdc++.h>
int solve(vector<int>&nums,int n,vector<int>&dp)
{
    //-------------------------Memoization---------------------------------------
//     if(n==0)
//     {
//         return nums[n];
//     }
//     if(n<0)
//     {
//         return 0;
//     }
//     if(dp[n]!=-1)
//     {
//         return dp[n];
//     }
//     int l=nums[n]+solve(nums,n-2,dp);
//     int r=0+solve(nums,n-1,dp);
//     return dp[n]=max(l,r);
    
    //-----------------------Tabulation--------------------------------------------------
//     dp[0]=nums[0];
//     for(int i=1;i<=n;i++)
//     {
//         int l=nums[i];
//         if(i>1)
//         {
//             l+=dp[i-2];
//         }
//         int r=dp[i-1];
//         dp[i]=max(l,r);
//     }
//     return dp[n];
   
    
    ///--------------------------------Space optimization-------------------------------
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<=n;i++)
    {
        int l=nums[i];
        if(i>1)
        {
            l+=prev2;
        }
        int r=prev;
        int curr=max(l,r);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n,-1);
    return solve(nums,n-1,dp);
}