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


// Recursive Approach
int solve(string s, int i, int j)
{
	if(i==j)
	{
		return 0;
	}
	
	if(isPalindrome(s,i,j)==true)
	{
		return 0;
	}
	
	int ans = INT_MAX;
	
	for(int k=i; k<=j-1; k++)
	{
		int temp = 1+solve(s,i,k)+solve(s,k+1,j);
		
		ans = min(ans,temp);
	}
	return ans;
	
}

// Memoization Approach
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
		int temp = 1+solve_Mem(s,i,k)+solve_Mem(s,k+1,j);
		
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
