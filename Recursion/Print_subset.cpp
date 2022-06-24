#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, int i, vector<int> &temp)
{
	if(i>=arr.size())
	{
		temp.push_back();
		return;
	}
	
	temp.push_back(arr[i]);
	solve(arr,i+1,temp);
	temp.pop_back();
	solve(arr,i+1,temp);
}

int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	vector<int> temp;
	solve(arr,0,temp);
	
	for(int i=0; i<temp.size())
	
	return 0;
}
