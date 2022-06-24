#include<bits/stdc++.h>
using namespace std;

int MCM(int* arr, int i, int j)
{
	if(i>=j)
	{
		return 0;
	}
	
	int minimum = INT_MAX;
	
	for(int k=i; k<=j-1; k++)
	{
		int tempAns = MCM(arr,i,k)+MCM(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
		
		minimum = min(minimum, tempAns); 
	}
	return minimum;
}

int main()
{
	int n;
	cin>>n;
	
	int*arr = new int[n];
	
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	int ans = MCM(arr,1,n-1);
	
	cout<<"MCM:"<<ans<<endl;
	
	return 0;
}
