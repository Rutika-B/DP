https://leetcode.com/problems/partition-array-for-maximum-sum/submissions/
class Solution {
public:
//     int solve(int ind,int n,vector<int>&arr,int k,vector<int>&dp)
//     {
//         if(ind==n)
//             return 0;
        
//         if(dp[ind]!=-1)
//             return dp[ind];
        
//         int l=0,maxs=0,maxans=0,maxnum=0;
        
//         for(int j=ind;j<min(n,(ind+k));j++)
//         {
//             l++;
//             maxnum=max(maxnum,arr[j]);
//             maxs=(maxnum*l)+solve(j+1,n,arr,k,dp);
//             maxans=max(maxans,maxs);
//         }
//         return dp[ind]=maxans;
//     }
    //----------------------------Tabulation---------------------------------
    int solve(int n,vector<int>&arr,int k)
    {
        vector<int>dp(n+1,0);

        
        for(int ind=n-1;ind>=0;ind--)
        {
            int l=0,maxs=0,maxans=0,maxnum=0;
        
            for(int j=ind;j<min(n,(ind+k));j++)
            {
                l++;
                maxnum=max(maxnum,arr[j]);
                maxs=(maxnum*l)+dp[j+1];
                maxans=max(maxans,maxs);
            }
            dp[ind]=maxans;
        }
        return dp[0];
        
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        // vector<int>dp(n,-1);
        // return solve(0,n,arr,k,dp);
        return solve(n,arr,k);
    }
};