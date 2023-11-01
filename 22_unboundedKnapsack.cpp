https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// int solve(int ind,int tar,vector<int>&w,vector<int>&v,vector<vector<int>>&dp)
// {
//     if(tar==0)
//         return 0;
//     if(ind==0)
//         return ((tar/w[0])*v[0]);
//     if(dp[ind][tar]!=-1)return dp[ind][tar];
//     int notpick=solve(ind-1,tar,w,v,dp);
//     int pick=0;
//     if(tar>=w[ind])
//         pick=v[ind]+solve(ind,tar-w[ind],w,v,dp);
//     return dp[ind][tar]=max(pick,notpick);
// }
// int solve(int ind,int tar,vector<int>&w,vector<int>&v,vector<vector<int>>&dp)
// {   
//     for(int i=0;i<=tar;i++)
//         dp[0][i]=(i/w[0])*v[0];
    
//     for(int i=1;i<=ind;i++)
//     {    for(int j=1;j<=tar;j++)
//          {   int notpick=dp[i-1][j];
//              int pick=0;
//             if(j>=w[i])
//             {    
//                 pick=v[i]+dp[i][j-w[i]];
//             }
//             dp[i][j]=max(pick,notpick);
//          }
//     }
//     return dp[ind][tar];
// }

int solve(int ind,int tar,vector<int>&w,vector<int>&v,vector<int>&dp)
{   
    for(int i=0;i<=tar;i++)
        dp[i]=(i/w[0])*v[0];
    
    for(int i=1;i<=ind;i++)
    {    for(int j=1;j<=tar;j++)
         {   int notpick=dp[j];
             int pick=0;
            if(j>=w[i])
            {    
                pick=v[i]+dp[j-w[i]];
            }
            dp[j]=max(pick,notpick);
         }
    }
    return dp[tar];
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
//     vector<vector<int>>dp(n,vector<int>(w+1,-1));
//         vector<vector<int>>dp(n,vector<int>(w+1,0));
            vector<int>dp(w+1,0);
    return solve(n-1,w,weight,profit,dp);
}
