#include <bits/stdc++.h>
using namespace std;
long long f(int ind,int prev,vector<vector<long long>>&v,int n,vector<vector<long long>>&dp)
{
    if(ind==n)
    {
        return 0;
    }
    if(dp[ind][prev+1]!=-1)
    {
        return dp[ind][prev+1];
    }
    long long l=0,r=0;
    if(prev==-1 || v[ind][0]>v[prev][1])
    {
        l=v[ind][2]+f(ind+1,ind,v,n,dp);
    }
    r=f(ind+1,prev,v,n,dp);
    return dp[ind][prev+1]=max(l,r);
}
int main()
{
    int n;
    cin>>n;
    int a,b,c;
    vector<vector<long long>>v(n,vector<long long>(3,0));
    vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
    for (int i = 0; i < n; i++)
    {
        cin>>a>>b>>c;
        v[i][0]=a;
        v[i][1]=b;
        v[i][2]=c;
    }
    sort(v.begin(),v.end());
    cout<<f(0,-1,v,n,dp);
    
 
   return 0;
}