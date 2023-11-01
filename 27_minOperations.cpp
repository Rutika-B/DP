https://www.codingninjas.com/codestudio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
int solve(int l1,int l2,string s,string t,vector<int>&dp)
{
    vector<int>tmp(l2+1,0);
    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            if(s[i-1]==t[j-1])
            {
                tmp[j]=1+dp[j-1];
            }
            else
            {
                tmp[j]=max(dp[j],tmp[j-1]);
            }
        }
        dp=tmp;
    }
    return dp[l2];
   
}
int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n=str.length();
    int m=ptr.length();
    vector<int>dp(m+1,0);
    int lcs=solve(n,m,str,ptr,dp);
    return (n-lcs)//deletion
        +(m-lcs);//insertion
}