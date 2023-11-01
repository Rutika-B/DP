https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include<bits/stdc++.h>
#define ll long long
int mod=1000000007;

//--------------------------------------------------------Memoization----------------------------------------------------
// int solve(int i,int j,int isTrue,string &exp,vector<vector<vector<int>>>&dp)
// {
//     if(i>j)
//         return 0;
//     if(i==j)
//     {
//         if(isTrue)
//         {
//             return exp[i]=='T';
//         }
//         else
//             return exp[i]=='F';
//     }
//     if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
//     ll ways=0;
//     for(int ind=i+1;ind<=j-1;ind+=2)
//     {
//         ll lt=solve(i,ind-1,1,exp,dp);
//         ll lf=solve(i,ind-1,0,exp,dp);
//         ll rt=solve(ind+1,j,1,exp,dp);
//         ll rf=solve(ind+1,j,0,exp,dp);
        
//         if(exp[ind]=='&')
//         {
//             if(isTrue)
//             {
//                 ways=(ways+(lt*rt)%mod)%mod;
//             }
//             else
//             {
//                 ways=(ways+(lt*rf)%mod+(lf*rt)%mod+(lf*rf)%mod)%mod;
//             }
//         }
//         else if(exp[ind]=='|')
//         {
//             if(isTrue)
//             {
//                 ways=(ways+(lt*rt)%mod+(lt*rf)%mod+(lf*rt)%mod)%mod;
//             }
//             else
//             {
//                 ways=(ways+(lf*rf)%mod)%mod;
//             }
//         }
//         else
//         {
//             if(isTrue)
//             {
//                 ways=(ways+(lt*rf)%mod+(lf*rt)%mod)%mod;
//             }
//             else
//             {
//                 ways=(ways+(lt*rt)%mod+(lf*rf)%mod)%mod;
//             }
//         }
//     }
//     return dp[i][j][isTrue]=ways;
// }

//---------------------------------------------Tabulation---------------------------------
int solve(int n,string &exp,vector<vector<vector<int>>>&dp)
{

    for(int i=0;i<n;i++)
    {
        dp[i][i][1]=(exp[i]=='T');
        dp[i][i][0]=(exp[i]=='F');
    }
    
     for(int i=n-1;i>=0;i--)
     {
         for(int j=i+1;j<n;j++)
         {
             for(int isTrue=0;isTrue<2;isTrue++)
             {
                ll ways=0;
                for(int ind=i+1;ind<=j-1;ind+=2)
                {
                    ll lt=dp[i][ind-1][1]%mod;
                    ll lf=dp[i][ind-1][0]%mod;
                    ll rt=dp[ind+1][j][1]%mod;
                    ll rf=dp[ind+1][j][0]%mod;

                    if(exp[ind]=='&')
                    {
                        if(isTrue)
                        {
                            ways=(ways+(lt*rt)%mod)%mod;
                        }
                        else
                        {
                            ways=(ways+(lt*rf)%mod+(lf*rt)%mod+(lf*rf)%mod)%mod;
                        }
                    }
                    else if(exp[ind]=='|')
                    {
                        if(isTrue)
                        {
                            ways=(ways+(lt*rt)%mod+(lt*rf)%mod+(lf*rt)%mod)%mod;
                        }
                        else
                        {
                            ways=(ways+(lf*rf)%mod)%mod;
                        }
                    }
                    else
                    {
                        if(isTrue)
                        {
                            ways=(ways+(lt*rf)%mod+(lf*rt)%mod)%mod;
                        }
                        else
                        {
                            ways=(ways+(lt*rt)%mod+(lf*rf)%mod)%mod;
                        }
                    }
                }
               dp[i][j][isTrue]=ways;
             }
         }
     }
    return dp[0][n-1][1];
}

int evaluateExp(string & exp) {

    int n=exp.size();
//     vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
//     return solve(0,n-1,1,exp,dp);
     vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,0)));
    return solve(n,exp,dp);
}