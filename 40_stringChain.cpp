https://www.codingninjas.com/codestudio/problems/longest-string-chain_3752111?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
#include<bits/stdc++.h>
bool compare(string a,string b)
{
    if(a.length()-b.length()!=1)
    {
        return false;
    }
    else
    {
        int i=0;
        int j=0;
       
        while(i<a.length())
        {
            if(a[i]!=b[j])
            {
              
                i++;
            }
            else
            {
                i++;
                j++;
            }
        }
        if(i==a.size() && j==b.size())
        {
            return true;
        }
        return false;
        
    }
}
bool comp(string a,string b)
{
    return a.size()<b.size();
}
int longestStrChain(vector<string> &arr)
{
    // Write your code here.g
    sort(arr.begin(),arr.end(),comp);
    int n=arr.size();
    int maxi=1;
    vector<int>count(n,1);
    for(int i=1;i<n;i++)
    {
        for(int prev=0;prev<i;prev++)
        {
            if(compare(arr[i],arr[prev]) && count[i]<count[prev]+1)
            {
                count[i]=count[prev]+1;
            }
        }
        maxi=max(maxi,count[i]);
    }
    return maxi;
}