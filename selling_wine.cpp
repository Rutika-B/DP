#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/library/wine-selling
int solve(int i,int j,int n,vector<int>&price)
{
    int yr=(n-(j-i));
    if (i==j)
    {
        return price[i]*yr;
    }
    return max(price[i]*yr+solve(i+1,j,n,price),price[j]*yr+solve(i,j-1,n,price));
    
}
int main()
{
    vector<int> price{2, 4, 6, 2, 5};
	int i, j, n = price.size();
	cout << solve(0, n-1, n, price) << endl;
 
   return 0;
}