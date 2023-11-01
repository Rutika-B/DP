https://www.codingninjas.com/codestudio/problems/count-square-submatrices-with-all-ones_3751502?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
int countSquares(int n, int m, vector<vector<int>> &arr) {
    // Write your code here.
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 || j==0)
            {
                c+=arr[i][j];
                continue;
            }
            else if(arr[i][j]==1)
            {
                arr[i][j]+=min(arr[i-1][j],min(arr[i-1][j-1],arr[i][j-1]));
                c+=arr[i][j];
            }
        }
    }
    return c;
}


