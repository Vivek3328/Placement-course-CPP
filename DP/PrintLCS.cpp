#include<bits/stdc++.h>
using namespace std;

void PrintLCS(string a, string b, int m, int n, string &s)
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
	
	int i=m;
	int j=n;
	
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
		{
			s.push_back(a[i-1]);
			i--;
			j--;
		}
		else if(dp[i][j-1]>dp[i-1][j])
		{
			j--;
		}
		else
		{
			i--;
		}
	}
	reverse(s.begin(), s.end());
}

int main()
{
	string a, b;
	cin>>a>>b;
	
	int m = a.length();
	int n = b.length();
	
	string s = "";
	
	PrintLCS(a,b,m,n,s);
	
   cout<<s<<endl;
	
	return 0;
}
