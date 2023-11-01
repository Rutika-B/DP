https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=1
// int solve(int ind,int tar,vector<int>&a,vector<vector<int>>&dp)
// {
//     if(ind==0)
//         if(tar%a[0]==0)
//             return tar/a[0];
//         else
//             return 1e9;
    
//     if(dp[ind][tar]!=-1)return dp[ind][tar];
    
//     int notpick=0+solve(ind-1,tar,a,dp);
//     int pick=1e9;
//     if(tar>=a[ind])
//         pick=1+solve(ind,tar-a[ind],a,dp);
//     return dp[ind][tar]=min(pick,notpick);
        
// }




// int solve(int ind,int tar,vector<int>&a,vector<vector<int>>&dp)
// {
//     for(int i=0;i<=tar;i++)
//     {
//         if(i%a[0]==0)
//             dp[0][i]=i/a[0];
//         else
//             dp[0][i]=1e9;
//     }
    
//     for(int i=1;i<=ind;i++)
//     {
//         for(int j=0;j<=tar;j++)
//         {
//             int notpick=dp[i-1][j];
//             int pick=1e9;
//             if(j>=a[i])
//                 pick=1+dp[i][j-a[i]];
//             dp[i][j]=min(pick,notpick);
//         }
//     }
//     return dp[ind][tar];        
// }

int solve(int ind,int tar,vector<int>&a,vector<int>&dp)
{
    for(int i=0;i<=tar;i++)
    {
        if(i%a[0]==0)
            dp[i]=i/a[0];
        else
            dp[i]=1e9;
    }
    
    for(int i=1;i<=ind;i++)
    {
        for(int j=0;j<=tar;j++)
        {
            int notpick=dp[j];
            int pick=1e9;
            if(j>=a[i])
                pick=1+dp[j-a[i]];
            dp[j]=min(pick,notpick);
        }
    }
    return dp[tar];        
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
//     vector<vector<int>>dp(num.size(),vector<int>(x+1,-1));
        vector<int>dp(vector<int>(x+1,-1));
    int ans=solve(num.size()-1,x,num,dp);
    if(ans>=1e9)return -1;
    return ans;
}