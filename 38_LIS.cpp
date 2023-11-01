https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include<bits/stdc++.h>
//------------------------------------Memoization----------------------------------------------
// int solve(int ind,int last,int n,int a[],vector<vector<int>>&dp)
// {
//     if(ind==n)
//         return 0;
//     if(dp[ind][last+1]!=-1)
//         return dp[ind][last+1];
//     int pick=0,notpick=0;
//     notpick=solve(ind+1,last,n,a,dp);
//     if(last==-1 || a[ind]>a[last])
//         pick=1+solve(ind+1,ind,n,a,dp);
//     return dp[ind][last+1]=max(pick,notpick);
// }


//--------------------------------Tabulation---------------------------------------------------------
//  int solve(int n,int a[],vector<vector<int>>&dp)
//  {
//      for(int ind=n-1;ind>=0;ind--)
//      {
//          for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--)
//          {
//                 int ans=0;
//                 ans=dp[ind+1][prev_ind+1];
//                 if(prev_ind==-1 || a[ind]>a[prev_ind])
//                     ans=max(ans,1+dp[ind+1][ind+1]);
//                 dp[ind][prev_ind+1]=ans;
//          }
//      }
//      return dp[0][0];
//  }


//--------------------------------------Space optimization-------------------------------------
//  int solve(int n,int a[],vector<int>&dp)
//  {
//      vector<int>curr(n+1,0);
//      for(int ind=n-1;ind>=0;ind--)
//      {
//          for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--)
//          {
//                 int ans=0;
//                 ans=dp[prev_ind+1];
//                 if(prev_ind==-1 || a[ind]>a[prev_ind])
//                     ans=max(ans,1+dp[ind+1]);
//                 curr[prev_ind+1]=ans;
//          }
//          dp=curr;
//      }
//      return dp[0];
//  }
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
//     vector<vector<int>>dp(n,vector<int>(n+1,-1));
//     return solve(0,-1,n,arr,dp);
    
//     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//     return solve(n,arr,dp);
    
//      vector<int>dp(n+1,0);
//     return solve(n,arr,dp);
    
//--------------------------------------Brute force--------------------------------------
//     vector<int>dp(n,1);
//     int ans=1;
//     for(int i=0;i<n;i++)
//     {
//         for(int prev=0;prev<i;prev++)
//         {
//             if(arr[prev]<arr[i])
//             {
//                 dp[i]=max(dp[i],dp[prev]+1);
//             }
//         }
//         ans=max(ans,dp[i]);
//     }
//     return ans;
   
    
 //----------------------------To print LIS----------------------------------------------------------
//     vector<int>count(n,1);
//     vector<int>hash(n,0);
//     for(int i=0;i<n;i++)
//     {
//         hash[i]=i;
//     }
//     int ans=1,lastindex=0;
//     for(int i=0;i<n;i++)
//     {
//         for(int prev=0;prev<i;prev++)
//         {
//             if(arr[prev]<arr[i])
//             {
//                 if(count[i]<count[prev]+1)
//                 {
//                     hash[i]=prev;
//                     count[i]=count[prev]+1;
//                 }
//             }
//         }
//         if(ans<count[i])
//         {
//             ans=count[i];
//             lastindex=i;
//         }
//     }
//     vector<int>s;
//     s.push_back(arr[lastindex]);
//     while(hash[lastindex]!=lastindex)
//     {
//         lastindex=hash[lastindex];
//         s.push_back(arr[lastindex]);
//     }
//     reverse(s.begin(),s.end());
//     for(auto &it:s)
//     {
//         cout<<it<<" ";
//     }
//     return ans;
    
    //-------------------------------------------via Binary Search--------------------------------
    vector<int>lis;
    lis.push_back(arr[0]);
    int l=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>lis.back())
        {
            lis.push_back(arr[i]);
            l++;
        }
        else
        {
            int ind=lower_bound(lis.begin(),lis.end(),arr[i])-lis.begin();
            lis[ind]=arr[i];
        }
        
    }
    return l;
}
