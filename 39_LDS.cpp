https://www.codingninjas.com/codestudio/problems/divisible-set_3754960?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include<bits/stdc++.h>
vector<int> divisibleSet(vector<int> &arr){
    // Write your code here.
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<int>count(n,1);
    vector<int>hash(n,0);
    int pos=0,maxi=1;
    for(int i=0;i<n;i++)
    {
        hash[i]=i;
        for(int prev=0;prev<i;prev++)
        {
            if(arr[i]%arr[prev]==0 && count[i]<count[prev]+1)
            {
                count[i]=count[prev]+1;
                hash[i]=prev;
            }
        }
        if(count[i]>maxi)
        {
            maxi=count[i];
            pos=i;
        }
    }
    vector<int>ans;
    ans.push_back(arr[pos]);
    while(hash[pos]!=pos)
    {
        pos=hash[pos];
        ans.push_back(arr[pos]);
    }
    
    return ans;
}