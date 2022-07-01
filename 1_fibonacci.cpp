#include <bits/stdc++.h>
using namespace std;
////Memoization technique;
// int f(int n, vector<int> &dp)
// {
//     if (n <= 1)
//     {
//         return n;
//     }
//     if (dp[n] != -1)
//         return dp[n];
//     return dp[n] = f(n - 1, dp) + f(n - 2, dp);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> dp(n + 1, -1);
//     int ans = f(n, dp);
//     cout << ans;

//     return 0;
// }
// time complexity--O(n);
// space--O(n)+O(n)--one for recursion stack another for dp data structure

//------------------------------This is tabulatio approach----------------------------------
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int>dp(n+1);
//     dp[0]=0;
//     dp[1]=1;
//     for (int i = 2; i <= n; i++)
//     {
//         dp[i]=dp[i-2]+dp[i-1];
//     }
//     cout<<dp[n];

//     return 0;
// }
// time complexity--O(n);
// space--O(n)- dp data structure
// --------------------------------Space optimization--------------------------------
int main()
{
    int n, curr;
    cin >> n;
    int t1 = 1;
    int t2 = 0;
    for (int i = 2; i <= n; i++)
    {
        curr = t1 + t2;
        t2 = t1;
        t1 = curr;
    }
    cout << curr;
    return 0;
}
// time complexity--O(n);
// space--O(1)- as no data structure required