https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
bool solve(int k,int n,vector<int>&arr)
{
    
    vector<bool>dp(k+1,0);
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
bool canPartition(vector<int> &arr, int n)
{

    int ts=0;
    for(int i=0;i<n;i++)
    {
        ts+=arr[i];
    }
    if(ts&1){return false;}
    else
    {
        return solve(ts/2,n,arr);
    }
}
