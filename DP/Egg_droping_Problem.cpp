#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int solve(int e, int f)
{
	if(f==1 || f==0)
	{
		return f;
	}
	
	if(e==1)
	{
		return f;
	}
	
	if(dp[e][f]!=-1)
	{
		return dp[e][f];
	}
	
	int mini = INT_MAX;
	
	for(int k=1; k<=f; k++)
	{
		int low,high;
		
		if(dp[e][f-k]!=-1)
		{
			high = dp[e][f-k];
		}
		else{
			high = solve(e,f-k);
			dp[e][f-k] = high;
			
		}
		
		if(dp[e-1][k-1]!=-1)
		{
			low = dp[e-1][k-1];
		}
		else{
			low = solve(e-1,k-1);
			dp[e-1][k-1] = low;
			
		}
		
		int temp = 1+max(low,high);
		
		mini = min(mini,temp);
	}
	
	return dp[e][f] =  mini;
}

int main()
{
	int e,f;
	cin>>e>>f;
	
	memset(dp,-1,sizeof(dp));
	
	int ans = solve(e,f);
	cout<<ans<<endl;
	
	return 0;
}
