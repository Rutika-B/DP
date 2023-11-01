https://www.codingninjas.com/codestudio/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include<bits/stdc++.h>
int solve(vector<int>&heights)
{
        int n=heights.size();
        stack<int>s;
        int maxa=0;
        for(int i=0;i<=n;i++)
        {
            while(!s.empty() && (i==n ||heights[i]<=heights[s.top()]))
            {
                int h=heights[s.top()];
                s.pop();
                int wid;
                if(s.empty())
                {
                    wid=i;
                }
                else
                {
                    int l=s.top();
                    wid=i-l-1;
                }
                maxa=max(maxa,h*wid);
            }
            s.push(i);
        }
        return maxa;
}
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	vector<int>heights(m,0);
    int maxarea=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==0)
            {
                heights[j]=0;
            }
            else
            {
                heights[j]+=1;
            }
        }
        maxarea=max(maxarea,solve(heights));
    }
    return maxarea;
}