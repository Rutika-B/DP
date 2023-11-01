#include <bits/stdc++.h>
using namespace std;
int f(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int left, right = INT_MAX;
    left = f(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
    if (n > 1)
    {
        right = f(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
    }
    return dp[n] = min(left, right);
}

// int spaceoptimization(int n, vector<int> &heights)
// {
   
//     int prev = 0;
//     int prev2 = 0, curr;
//     for (int i = 1; i <= n; i++)
//     {
//         int l = prev + abs(heights[i] - heights[i - 1]);
//         int r = INT_MAX;
//         if (i > 1)
//         {
//             r = prev2 + abs(heights[i] - heights[i - 2]);
//         }
//         curr = min(l, r);
//         prev2 = prev;
//         prev = curr;
//     }
//     return curr;
// }
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n + 1, -1);
    return f(n - 1, heights, dp);
}
int main()
{
    int n;
    cin >> n;
    vector<int> heights(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    //------------Memoization----------------------------------------
    int minEnrgy = frogJump(n, heights);
    cout << minEnrgy << endl;


    //------------------Space optimization--------------------------------------
    // int spaceopti = spaceoptimization(n, heights);
}
///-----------------------------------Tabular approach__________---------------------------------
https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos