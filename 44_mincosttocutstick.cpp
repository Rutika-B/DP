https://www.codingninjas.com/codestudio/problems/cost-to-cut-a-chocolate_3208460?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include<bits/stdc++.h>
// int solve(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
// {
//     if(j<i)
//         return 0;
//     if(dp[i][j]!=-1)return dp[i][j];
//     int mini=1e9;
//     for(int ind=i;ind<=j;ind++)
//     {
//         int step=cuts[j+1]-cuts[i-1]+solve(i,ind-1,cuts,dp)+solve(ind+1,j,cuts,dp);
//         mini=min(step,mini);
//     }
//     return dp[i][j]=mini;
// }

//---------------------------------------Tabulation-----------------------------------------------------
int solve(int c,vector<int>&cuts,vector<vector<int>>&dp)
{
   for(int i=c;i>=1;i--)
   {
       for(int j=1;j<=c;j++)
       {
            
               if(i>j)
                   continue;
              int mini=1e9;
                for(int ind=i;ind<=j;ind++)
                {
                    int step=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                    mini=min(step,mini);
                }
               dp[i][j]=mini;
       }
   }
    return dp[1][c];
}
int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
//     vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
//     return solve(1,c,cuts,dp);
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
    return solve(c,cuts,dp);
}