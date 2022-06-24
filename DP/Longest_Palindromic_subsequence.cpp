#include<bits/stdc++.h>
using namespace std;

int solve(string a, string b, int m, int n)
{
	int dp[m+1][n+1];
	
	for(int i=0; i<m+1; i++)
	{
		for(int j=0; j<n+1; j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j]=0;
			}
			else if(a[i-1]==b[j-1])
			{
				dp[i][j] = 1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[m][n];
}

int LPS(string a, int m)
{
	string b = a; 
	reverse(b.begin(), b.end());
	
	
	int n =   b.length();
	
	int ans = solve(a,b,m,n);
	return ans;
}

int main()
{
	string a;
	cin>>a;

	int m = a.length();
	
	cout<< LPS(a,m)<<endl;
	
	return 0;
}
