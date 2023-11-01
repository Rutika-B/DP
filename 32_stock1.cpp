https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mini=prices[0],profit=0;
    for(int i=1;i<prices.size();i++)
    {
        int cost=prices[i]-mini;
        profit=max(cost,profit);
        mini=min(mini,prices[i]);        
    }
    return profit;
}