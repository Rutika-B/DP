#include <bits/stdc++.h>
using namespace std;
//------------------------------------------Recursive Solution--------------------------------------------------
// int fjump(int n, vector<int> &a, int k)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     int ans = INT_MAX;
//     for (int i = 1; i <= k; i++)
//     {
//         if (n - i >= 0)
//         {
//             int jump = fjump(n - i, a, k) + abs(a[n] - a[n - i]);
//             ans = min(ans, jump);
//         }
//     }
//     return ans;
// }
//-----------------------------------------Memoization-------------------------------------------------
// int fjump(int n, vector<int> &a, int k, vector<int> &dp)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }
//     int ans = INT_MAX;
//     for (int i = 1; i <= k; i++)
//     {
//         if (n - i >= 0)
//         {
//             int jump = fjump(n - i, a, k, dp) + abs(a[n] - a[n - i]);
//             ans = min(ans, jump);
//         }
//     }
//     return dp[n] = ans;
// }
///-------------------------------------Tabular------------------------------------------------

int solveUtil(int n, vector<int>& height, vector<int>& dp, int k){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps = INT_MAX;

        for(int j=1;j<=k;j++){
            if(i-j>0){
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                mmSteps= min(jump, mmSteps);
            }
        }
        dp[i]= mmSteps;
    }
    return dp[n-1];
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<int> dp(n+1, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // int c = fjump(n - 1, a, k);
 
    int c=solveUtil(n,a,dp,k);

    cout << c << endl;

    return 0;
}