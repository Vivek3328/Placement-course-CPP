#include<bits/stdc++.h>
using namespace std;

int LCS(string a, string b, int m, int n)
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
			else if(a[i-1]==b[j-1] && i!=j)
			{
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[m][n];
}

int LRS(string s, int l)
{
	string a = s;
	string b = s;
	int m = l;
	int n = l;
	int ans = LCS(a,b,m,n);
	return ans;
}

int main()
{
	string s;
	cin>>s;
	
	int l = s.length();
	
	cout<<LRS(s,l)<<endl;
	
	return 0;
}
