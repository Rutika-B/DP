https://leetcode.com/problems/wildcard-matching/submissions/
class Solution {
public:
    
// bool solve(int i,int j,string p,string t)
// {
//     if(i<0 && j<0)
//         return true;
//     if(i<0 && j>=0)
//         return false;
//     if(j<0 && i>=0)
//     {
//         for(int k=0;k<=i;k++)
//         {
//             if(p[k]!='*')
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
//     if(p[i]==t[j] || p[i]=='?')
//         return solve(i-1,j-1,p,t);
//     if(p[i]=='*')
//     {
//         return (solve(i-1,j,p,t)or solve(i,j-1,p,t));
//     }
//     // if(p[i]!=t[j])
//        return false;
    
// }
    
// int solve(int i,int j,string p,string t,vector<vector<int>>&dp)
// {
//     if(i<0 && j<0)
//     {
//         return 1;
//     }
//     if(i<0 && j>=0)
//     {
//         return 0;
//     }
//     if(j<0 && i>=0)
//     {
//         for(int k=0;k<=i;k++)
//         {
//             if(p[k]!='*')
//             {
//                 return 0;
//             }
//         }
//         return 1;
//     }
//     if(dp[i][j]!=-1)
//     {
//         return dp[i][j];
//     }
//     if(p[i]==t[j] || p[i]=='?')
//     {    
//         return dp[i][j]=solve(i-1,j-1,p,t,dp);
//     }
//     else{
    
//         if(p[i]=='*')
//         {
//             return dp[i][j]=(solve(i-1,j,p,t,dp) or solve(i,j-1,p,t,dp));
//         }
//         else
//         {
//             return dp[i][j]=0;
//         }
//     }
// }
    bool isallStar(int s,int e,string p)
    {
        for(int i=s-1;i<e;i++)
        {
            if(p[i]!='*')
                return false;
        }
        return true;
    }
    int solve(int l1,int l2,string p,string t,vector<vector<int>>&dp)
    {
        dp[0][0]=1;
        for(int i=1;i<=l1;i++)
        {
            if(isallStar(1,i,p))
            {
                dp[i][0]=1;
            }
            else
            {
                dp[i][0]=0;
            }
        }
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                if(p[i-1]==t[j-1]|| p[i-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    if(p[i-1]=='*')
                    {
                        dp[i][j]=(dp[i][j-1]or dp[i-1][j]);
                    }
                    else
                    {
                        dp[i][j]=0;
                    }
                }
            }
        }
        return dp[l1][l2];
    }
    bool isMatch(string s, string p) {
        int l1=p.length();
        int l2=s.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        return solve(l1,l2,p,s,dp);
    }
};