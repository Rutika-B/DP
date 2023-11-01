https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1
//User function Template for C++

class Solution{
  public:
    // int solve(int i,int j,string A,vector<vector<int>>&dp)
    // {
    //     if(i==j)
    //     {
    //         return 1;
    //     }
    //     if(i>j){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1)
    //     {
    //         return dp[i][j];
    //     }
    //     if(A[i]==A[j])
    //     {
    //         return dp[i][j]=2+solve(i+1,j-1,A,dp);
    //     }
    //     else
    //     {
    //         return dp[i][j]=max(solve(i+1,j,A,dp),solve(i,j-1,A,dp));
    //     }
    // }
    
    //--------------------------------------------Tabulation-------------------------
    int solve(int n,string A,vector<vector<int>>&dp)
    {
        
        
        for(int i=n;i>=0;i--)
        {
            for(int j=i;j<=n;j++)
            {
                // if(i>j){
                //     continue;
                // }
                if(i==j)
                {
                    dp[i][j]=1;
                    continue;
                }
                if(A[i]==A[j])
                {
                   dp[i][j]=2+dp[i+1][j-1];
                }
                else
                {
                   dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
                // cout<<dp[i][j]<<endl;
            }
        }
        return dp[0][n];
        
    }
    int longestPalinSubseq(string A) {
        //code here
        int n=A.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solve(0,n-1,A,dp);
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        return solve(n-1,A,dp);
    }
};