https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// int solve(int ind,int l,vector<int>&v,vector<vector<int>>&dp)
// {
//     if(l==0)
//         return 0;
//     if(ind==0)
//         return (l*v[0]);
//     if(dp[ind][l]!=-1)return dp[ind][l];
//     int pick=0,notpick=0;
//     if(l>0)
//         notpick=solve(ind-1,l,v,dp);
//     if(ind+1<=l)
//         pick=v[ind]+solve(ind,l-(ind+1),v,dp);
//     return dp[ind][l]=max(pick,notpick);
// }

// int solve(int ind,int l,vector<int>&v,vector<vector<int>>&dp)
// {    
//     for(int i=0;i<=l;i++)
//         dp[0][i]=(i*v[0]);
    
//     for(int i=1;i<=ind;i++)
//     {
//         for(int j=1;j<=l;j++)
//         {
//             int pick=0,notpick=0;

//             notpick=dp[i-1][j];
//             if(i+1<=j)
//             {   
//                 pick=v[i]+dp[i][j-(i+1)];
//             }
//             dp[i][j]=max(pick,notpick);
//         }
//     }
//     return dp[ind][l];
// }


int solve(int ind,int l,vector<int>&v,vector<int>&dp)
{    
    for(int i=0;i<=l;i++)
        dp[i]=(i*v[0]);
    
    for(int i=1;i<=ind;i++)
    {
        for(int j=1;j<=l;j++)
        {
            int pick=0,notpick=0;

            notpick=dp[j];
            if(i+1<=j)
            {   
                pick=v[i]+dp[j-(i+1)];
            }
            dp[j]=max(pick,notpick);
        }
    }
    return dp[l];
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.w
//     vector<vector<int>>dp(n,vector<int>(n+1,-1));
//         vector<vector<int>>dp(n,vector<int>(n+1,0));
           vector<int>dp(n+1,0);
    return solve(n-1,n,price,dp);
    
}
