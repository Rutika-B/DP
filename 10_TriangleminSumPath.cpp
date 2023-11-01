https://leetcode.com/problems/triangle/submissions/
class Solution {
public:
// int solve(int i,int j,int n,vector<vector<int>>&a,vector<vector<int>>&dp)
int solve(int i,int j,int n,vector<vector<int>>&a,vector<int>&dp)
{ 
//     if(i==n)
//     {
//         return a[i][j];
//     }
//     int l=a[i][j]+solve(i+1,j,n,a);
//     int r=a[i][j]+solve(i+1,j+1,n,a);
//     return min(l,r);
    
    
    
//     if(i==n)
//     {
//         return a[i][j];
//     }
//     if(dp[i][j]!=-1)
//         return dp[i][j];
//     int l=a[i][j]+solve(i+1,j,n,a,dp);
//     int r=a[i][j]+solve(i+1,j+1,n,a,dp);
//     return dp[i][j]=min(l,r);
    
    
    
//     dp[0][0]=a[0][0];

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=0;j<=i;j++)
//         {
//             int d=1e7,up=1e7;
//             if(j>0)
//             {
//                    d=dp[i-1][j-1]; 
//             }  
//             if(j!=i)
//             {
//                 up=dp[i-1][j];
//             }
//             dp[i][j]=min(d+a[i][j],up+a[i][j]);
//         }
//     }
//     int ans=1e7;
//     for(int i=0;i<=n;i++)
//     {
//         ans=min(ans,dp[n][i]);
//     }
//     return ans;
    
    
    dp[0]=a[0][0];

    for(int i=1;i<=n;i++)
    {
        vector<int>tmp(i+1,0);
        for(int j=0;j<=i;j++)
        {
            int d=1e7,up=1e7;
            if(j>0)
            {
                   d=dp[j-1]; 
            }  
            if(j!=i)
            {
                up=dp[j];
            }
            tmp[j]=min(d+a[i][j],up+a[i][j]);
        }
        dp=tmp;
    }
    int ans=1e7;
    for(int i=0;i<=n;i++)
    {
        ans=min(ans,dp[i]);
    }
    return ans;
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<int>dp(n,-1);
        return solve(0,0,n-1,triangle,dp);
    }
};