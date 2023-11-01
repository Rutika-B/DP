https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// int solve(int ind,int tar,vector<int>&a,vector<vector<int>>&dp)//memoization & tabulation
int solve(int ind,int tar,vector<int>&a,vector<int>&dp)//space optimization
{
//     if(tar==0)
//         return 1;
    
//     if(ind==0)
//         if(a[0]==tar)
//             return 1;
//         else
//             return 0;
    
//     if(dp[ind][tar]!=-1)return dp[ind][tar];
    
//     int notpick=solve(ind-1,tar,a,dp);
//     int pick;
//     if(a[ind]<=tar)
//         pick=solve(ind-1,tar-a[ind],a,dp);
//     else
//         pick=0;
    
//     return dp[ind][tar]=pick+notpick;
    
    
    
    //--------------------Tabulation-----------------
    
//     for(int i=0;i<=ind;i++)
//     {
//         dp[i][0]=1;
//     }
//     if(a[0]<=tar) 
//         dp[0][a[0]]=1;
    
//     for(int i=1;i<=ind;i++)
//     {
//         for(int j=1;j<=tar;j++)
//         {
//             int pick=0;
//             if(a[i]<=j)
//                 pick=dp[i-1][j-a[i]];
//             int notpick=dp[i-1][j];
//             dp[i][j]=pick+notpick;
//         }
//     }
//     return dp[ind][tar];
    
    
    
    
//     Space optimization
    
    if(a[0]<=tar) 
    {    
        dp[a[0]]=1;
    }
    dp[0]=1;
    vector<int>tmp(tar+1,0);
    tmp[0]=1;
    for(int i=1;i<=ind;i++)
    {
        for(int j=1;j<=tar;j++)
        {
            int pick=0;
            if(a[i]<=j)
                pick=dp[j-a[i]];
            int notpick=dp[j];
            tmp[j]=pick+notpick;
        }
        dp=tmp;
    }
    return dp[tar];
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
//     vector<vector<int>>dp(num.size(),vector<int>(tar+1,-1));
//         vector<vector<int>>dp(num.size(),vector<int>(tar+1,0));
    vector<int>dp(tar+1,0);
    return solve(num.size()-1,tar,num,dp);
}




