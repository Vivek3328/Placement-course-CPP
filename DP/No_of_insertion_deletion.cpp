#include<bits/stdc++.h>
using namespace std;

pair<int,int> del_insertion(string a, string b, int m, int n)
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
	
	pair<int,int> ans;
	
	ans.first = m-dp[m][n];
	ans.second = n-dp[m][n];
	
	return ans;
}

int main()
{
	string a, b;
	cin>>a>>b;
	
	int m = a.length();
	int n = b.length();
	
	pair<int,int> ans = del_insertion(a,b,m,n);
	
	cout<<"Deletion:"<<ans.first<<endl;
	cout<<"Insertion:"<<ans.second<<endl;
	
	return 0;
}
