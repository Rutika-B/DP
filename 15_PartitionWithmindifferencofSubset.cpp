https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

bool solve(int k,int n,vector<int>&arr,vector<bool>&dp)
{
    dp[0]=1;
    dp[arr[0]]=1;
    vector<bool>tmp(k+1,0);
    tmp[0]=1;
    for(int i=1;i<n;i++)
    {
   
        for(int target=1;target<=k;target++)
        {
                bool notpick=dp[target];
                bool pick=false;
                if(target>=arr[i])
                {
                    pick=dp[target-arr[i]];
                }
              tmp[target]=pick|notpick;
        }
        dp=tmp;
    }
    return dp[k];
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
    long long total_sum=0;
    
    for(int i=0;i<n;i++)
    {
        total_sum+=arr[i];
    }
    vector<bool>dp(total_sum/2+1,0);
    
    if(solve(total_sum/2,n,arr,dp))
    {
        return abs((total_sum-total_sum/2)-total_sum/2);
    }
    for(int target=total_sum/2-1;target>=0;target--)
    {
        if(dp[target])
        {
            int secondSubsetSum=total_sum-target;
            return abs(secondSubsetSum-target);
        }
    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    
}





