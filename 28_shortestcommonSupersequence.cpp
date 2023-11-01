https://www.codingninjas.com/codestudio/problems/shortest-supersequence_4244493?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
#include<bits/stdc++.h>
int solve(int l1,int l2,string s,string t,vector<vector<int>>&dp)
{

    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[l1][l2];
}
string lcs(string s, string t,int l1,int l2)
{
    vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
    int a=solve(l1,l2,s,t,dp);   
     int i=l1,j=l2;
    string ans="";
    while(i>0&&j>0)
    {
        if(s[i-1]==t[j-1])
        {
            ans+=s[i-1];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                ans+=s[i-1];
                i--;
            }
            else
            {
                ans+=t[j-1];
                j--;
            }
        }   
                                  
    }
    while(i>0)
    {
        ans+=s[i-1];
        i--;
    }
    while(j>0)
    {
        ans+=t[j-1];
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
string shortestSupersequence(string a, string b)
{
	// Write your code here.
    int l1=a.length();
    int l2=b.length();
    return lcs(a,b,l1,l2);
  
       
}