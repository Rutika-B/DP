https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// int solve(int l1,int l2,string s,string t)
// {
//     vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
//     int ans=0;
//     for(int i=1;i<=l1;i++)
//     {
//         for(int j=1;j<=l2;j++)
//         {
//             if(s[i-1]==t[j-1])
//             {
//                 dp[i][j]=1+dp[i-1][j-1];
//                 ans=max(ans,dp[i][j]);
//             }
            
//         }
//     }
//     return ans;
// }
int solve(int l1,int l2,string s,string t)
{
    vector<int>dp(l2+1,0);
    vector<int>tmp(l2+1,0);
    int ans=0;
    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            if(s[i-1]==t[j-1])
            {
                tmp[j]=1+dp[j-1];
                ans=max(ans,tmp[j]);
            }   
            else
            {
                tmp[j]=0;
            }
        }
        dp=tmp;
        
    }
    return ans;
}
int lcs(string &str1, string &str2){
	//	Write your code here.
    int l1=str1.length(),l2=str2.length();
    return solve(l1,l2,str1,str2);
}