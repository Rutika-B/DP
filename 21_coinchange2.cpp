https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
#include <bits/stdc++.h>
// long solve(int ind,int tar,int *a,vector<vector<long>>&dp)
// {
//     if(tar==0)
//         return 1;
//     if(ind==0)
//         if(tar%a[0]==0)
//             return 1;
//         else
//             return 0;
//     if(dp[ind][tar]!=-1)return dp[ind][tar];
    
//     long notpick=solve(ind-1,tar,a,dp);
//     long pick=0;
//     if(tar>=a[ind])
//         pick=solve(ind,tar-a[ind],a,dp);
//     return dp[ind][tar]=pick+notpick;
// }

// long solve(int ind,int tar,int *a,vector<vector<long>>&dp)
// {

//     for(int i=0;i<=tar;i++)
//     {
//          if(i%a[0]==0)
//              dp[0][i]=1;

//     }
//     for(int i=1;i<=ind;i++)
//     {
//         for(int j=0;j<=tar;j++)
//         {
//             long notpick=dp[i-1][j];
//             long pick=0;
//             if(j>=a[i])
//                 pick=dp[i][j-a[i]];
//             dp[i][j]=pick+notpick;

//         }
//     }
//     return dp[ind][tar];    
// }

long solve(int ind,int tar,int *a,vector<long>&dp)
{

    for(int i=0;i<=tar;i++)
    {
         if(i%a[0]==0)
             dp[i]=1;

    }
    for(long i=1;i<=ind;i++)
    {
        for(long j=0;j<=tar;j++)
        {
            long notpick=dp[j];
            long pick=0;
            if(j>=a[i])
                pick=dp[j-a[i]];
            dp[j]=pick+notpick;

        }
    }
    return dp[tar];    
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
//     vector<vector<long>>dp(n,vector<long>(value+1,-1));
//         vector<vector<long>>dp(n,vector<long>(value+1,0));
            vector<long>dp(value+1,0);

    return solve(n-1,value,denominations,dp);
}