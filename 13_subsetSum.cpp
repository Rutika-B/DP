https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1
bool solve(int ind,int target,vector<int>&arr,vector<vector<int>>&dp)
{
    if(target==0)return true;
    if(ind==0)
    {
        if(arr[ind]==target)return true;
        else 
            return false;
    }
    if(dp[ind][target]!=-1)
        return dp[ind][target];
    bool notpick=solve(ind-1,target,arr,dp);
    bool pick;
    if(target>=arr[ind])
    {
        pick=solve(ind-1,target-arr[ind],arr,dp);
    }
    else
    {
        pick=false;
    }
    return dp[ind][target]= (pick|notpick);
    
    
    
    
    
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return solve(n-1,k,arr,dp);
    
    
//     vector<vector<bool>>dp(n,vector<bool>(k+1,0));
//     for(int i=0;i<n;i++)dp[i][0]=1;
//     dp[0][arr[0]]=1;
//     for(int i=1;i<n;i++)
//     {
//         for(int target=1;target<=k;target++)
//         {
//                 bool notpick=dp[i-1][target];
//                 bool pick=false;
//                 if(target>=arr[i])
//                 {
//                     pick=dp[i-1][target-arr[i]];
//                 }
//               dp[i][target]=pick|notpick;
//         }
//     }
//     return dp[n-1][k];
    
    
//     vector<bool>dp(k+1,0);
//     dp[0]=1;
//     dp[arr[0]]=1;
//     vector<bool>tmp(k+1,0);
//     tmp[0]=1;
//     for(int i=1;i<n;i++)
//     {
   
//         for(int target=1;target<=k;target++)
//         {
//                 bool notpick=dp[target];
//                 bool pick=false;
//                 if(target>=arr[i])
//                 {
//                     pick=dp[target-arr[i]];
//                 }
//               tmp[target]=pick|notpick;
//         }
//         dp=tmp;
//     }
//     return dp[k];
    
}