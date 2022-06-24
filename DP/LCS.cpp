#include <bits/stdc++.h>
using namespace std;

// Recursive Approach
int LCS(string a , string b, int n, int m)
{
	if(n==0 || m==0)
	{
		return 0;
	}
	
	if(a[n-1]==b[m-1])
	{
		return 1+LCS(a,b,n-1,m-1);
	}
	else
	{
		return max(LCS(a,b,n,m-1),LCS(a,b,n-1,m));
	}
}

// Memoization Approach
int LCSMem(string a , string b, int n, int m)
{
	if(n==0 || m==0)
	{
		return 0;
	}
	
	int dp[n+1][m+1];
	memset(dp,-1,sizeof(dp));
	
	if(dp[n][m]!=-1)
	{
		return dp[n][m];
	}
	
	if(a[n-1]==b[m-1])
	{
		return dp[n][m]= 1+LCS(a,b,n-1,m-1);
	}
	else
	{
		return dp[n][m]= max(LCS(a,b,n,m-1),LCS(a,b,n-1,m));
	}
}

// Top-Down Approach
int Top_DownLCS(string a, string b, int n, int m)
{
	int dp[n+1][m+1];
	
	for(int i=0; i<n+1; i++)
	{
		for(int j=0; j<m+1; j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j]=0;
			}
			else if(a[i-1]==b[j-1])
			{
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	return dp[n][m];
}

int main()
{
	string a ,b;
	cin>>a>>b;
	
	int n = a.length();
	int m = b.length();
	
	cout<<"Recursive:"<<" "<<LCS(a,b,n,m)<<endl;
	cout<<"Memoization:"<<" "<<LCSMem(a,b,n,m)<<endl;	
	cout<<"Top-Down:"<<" "<<Top_DownLCS(a,b,n,m)<<endl;
	return 0;
}
