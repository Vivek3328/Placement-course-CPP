#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(string s, int i, int j)
{
	if(i>j)
	{
		return false;
	}
	
	while(i<=j)
	{
		if(s[i]!=s[j])
		{
			return false;
			break;
		}
		i++;
		j--;
	}
	return true;
}


// Optimized Memoization Approach
int solve_Mem(string s, int i, int j)
{
	if(i==j)
	{
		return 0;
	}
	
	if(isPalindrome(s,i,j)==true)
	{
		return 0;
	}
	
	int dp[i+1][j+1];
	memset(dp,-1,sizeof(dp));
	
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	
	int ans = INT_MAX;
	
	for(int k=i; k<=j-1; k++)
	{
		int left,right;
		if(dp[i][k]!=-1)
		{
			left = dp[i][k];
		}
		else
		{
			left = solve_Mem(s,i,k);
			dp[i][k]= left;
		}
		
		if(dp[k+1][j]!=-1)
		{
			right = dp[k+1][j];
		}
		else
		{
			right = solve_Mem(s,k+1,j);
			dp[k+1][j]=right;
		}
		int temp = 1+left+right;
		
		ans = min(ans,temp);
	}
	
	dp[i][j] = ans;
	
	return ans;
	
}


int main()
{
	string s;
	cin>>s;
	int n = s.length();
	
	int ans = solve_Mem(s,0,n-1);
	
	cout<<ans<<endl;
	
	
	return 0;
}
