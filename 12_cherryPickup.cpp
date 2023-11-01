https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>
int solve(int i,int j1,int j2,int r,int c,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp)
{
    if(j1<0 || j1>=c || j2<0 || j2>=c)
    {
        return -1e9;
    }
    if(i==r-1)
    {
        if(j1==j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1]+grid[i][j2];
        }
    }
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
    int maxi=0;
    for(int dj1=-1;dj1<=1;dj1++)
    {
        for(int dj2=-1;dj2<=1;dj2++)
        {
            int value=0;
            if(j1==j2)
            {
                value=grid[i][j1];
            }
            else
            {
                value=grid[i][j1]+grid[i][j2];
            }
            value+=solve(i+1,dj1+j1,dj2+j2,r,c,grid,dp);
            maxi=max(value,maxi);
        }
    }
    return dp[i][j1][j2]=maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return solve(0,0,c-1,r,c,grid,dp);
}