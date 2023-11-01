https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// int solve(int ind,int k,vector<int>&w,vector<int>&v,vector<vector<int>>&dp)
// {
//     if(k==0)
//         return 0;
//     if(ind==0)
//         if(k>=w[0])
//             return v[0];
//         else
//             return 0;
//     if(dp[ind][k]!=-1)return dp[ind][k];
//     int notpick=solve(ind-1,k,w,v,dp);
//     int pick=0;
//     if(k>=w[ind])
//         pick=v[ind]+solve(ind-1,k-w[ind],w,v,dp);
//     return dp[ind][k]=max(pick,notpick);
// }


//------------------------------Tabulation---------------------
// int solve(int ind,int k,vector<int>&w,vector<int>&v,vector<vector<int>>&dp)
// {

   
//     for(int wt=w[0];wt<=k;wt++)
//             dp[0][wt]=v[0];

    
//     for(int i=1;i<=ind;i++)
//     {
//         for(int wt=1;wt<=k;wt++)
//         {
//             int notpick=dp[i-1][wt];
//             int pick=0;
//             if(wt>=w[i])
//             pick=v[i]+dp[i-1][wt-w[i]];
//             dp[i][wt]=max(pick,notpick);
//         }
//     }    
    
//     return dp[ind][k];
// }
//----------------------------------------Space optimization----------------------
// int solve(int ind,int k,vector<int>&w,vector<int>&v,vector<int>&dp)
// {  
//     for(int wt=w[0];wt<=k;wt++)
//             dp[wt]=v[0];

//     vector<int>tmp(k+1,0);
//     for(int i=1;i<=ind;i++)
//     {
//         for(int wt=1;wt<=k;wt++)
//         {
//             int notpick=dp[wt];
//             int pick=0;
//             if(wt>=w[i])
//             pick=v[i]+dp[wt-w[i]];
//             tmp[wt]=max(pick,notpick);
//         }
//         dp=tmp;
//     }    
    
//     return dp[k];
// }


//-----------------------we dont even required to create tmp vector, modification can be done in dp array itself, if we will start from last index
int solve(int ind,int k,vector<int>&w,vector<int>&v,vector<int>&dp)
{  
    for(int wt=w[0];wt<=k;wt++)
            dp[wt]=v[0];
    
    for(int i=1;i<=ind;i++)
    {
        for(int wt=k;wt>=1;wt--)
        {
            int notpick=dp[wt];
            int pick=0;
            if(wt>=w[i])
            pick=v[i]+dp[wt-w[i]];
            dp[wt]=max(pick,notpick);
        }
      
    }    
    return dp[k];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
//     vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
//     vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
    vector<int>dp(maxWeight+1,0);
    
    return solve(n-1,maxWeight,weight,value,dp);
}