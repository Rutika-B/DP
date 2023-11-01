//--------------------------------- same like 17_countPartitions
https://www.codingninjas.com/codestudio/problems/target-sum_4127362?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

int solve(int ind,int tar,vector<int>&a,vector<int>&dp)
{
//    
    
    ///---------------------------------Space optijmization-----------
    
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
            tmp[j]=(pick+notpick);
        }
        dp=tmp;
    }
    return dp[tar];
    
}
int countPartitions(int n, int d, vector<int> &arr) {
    
    int total_sum=0;
    for(auto &i:arr)total_sum+=i;

    int target=(total_sum-d)/2;
    if(total_sum-d<0) return 0;
    if((total_sum-d)%2==1) return 0;

    vector<int>dp(target+1,0);
    return solve(n-1,target,arr,dp);
}
int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    return countPartitions(n,target,arr);
}
