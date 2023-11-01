https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
int mod=(int)(1e9+7);
// int solve(int ind,int tar,vector<int>&a,vector<vector<int>>&dp)
int solve(int ind,int tar,vector<int>&a,vector<int>&dp)
{
//     if(ind==0)
//         if(tar==0 && a[0]==0){return 2;}
//         else if(tar==0 || tar==a[0]){return 1;}
//         else 
//             return 0;
    
//     if(dp[ind][tar]!=-1)return dp[ind][tar];
    
//     int notpick=solve(ind-1,tar,a,dp);
//     int pick=0;
//     if(a[ind]<=tar)
//         pick=solve(ind-1,tar-a[ind],a,dp);
   
    
//     return dp[ind][tar]=(pick+notpick)%mod;
    
    
    
//     if(a[0]==0)//take it, not take it
//         dp[0][0]=2;
//     else
//         dp[0][0]=1;//not take it
    
//     if(a[0]!=0 && a[0]<=tar) //take it
//         dp[0][a[0]]=1;
    
//     for(int i=1;i<=ind;i++)
//     {
//         for(int j=0;j<=tar;j++)
//         {
//             int pick=0;
//             if(a[i]<=j)
//                 pick=dp[i-1][j-a[i]];
//             int notpick=dp[i-1][j];
//             dp[i][j]=(pick+notpick)%mod;
//         }
//     }
//     return dp[ind][tar];
    
    
    
    
    
    
    if(a[0]==0)//take it, not take it
        dp[0]=2;
    else
        dp[0]=1;//not take it
    vector<int>tmp(tar+1,0);
    if(a[0]!=0 && a[0]<=tar) //take it
        dp[a[0]]=1;
    
    for(int i=1;i<=ind;i++)
    {
        for(int j=0;j<=tar;j++)
        {
            int pick=0;
            if(a[i]<=j)
                pick=dp[j-a[i]];
            int notpick=dp[j];
            tmp[j]=(pick+notpick)%mod;
        }
        dp=tmp;
    }
    return dp[tar];
    
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int total_sum=0;
    for(auto &i:arr)total_sum+=i;

    int target=(total_sum-d)/2;
    if(total_sum-d<0) return 0;
    if((total_sum-d)%2==1) return 0;
//     vector<vector<int>>dp(n,vector<int>(target+1,-1));
//         vector<vector<int>>dp(n,vector<int>(target+1,0));
    vector<int>dp(target+1,0);
    return solve(n-1,target,arr,dp);
}


