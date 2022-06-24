#include <bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
	 	int n;
	 	cin>>n;
	 	
	 	vector<string> arr(n);	 	
	 	for(int i=0; i<n; i++)
	 	{
	 		cin>>arr[n];
		 }
		 
		 map<char,int> start,fin;
		 map<string,int> s;
		 int ans=0;
		 for(int i=0; i<n; i++)
		 {
		 	ans+=(start[arr[i][0]]+fin[arr[i][1]]-2*s[arr[i]]);
		 	start[arr[i][0]]++;
		 	fin[arr[i][1]]++;
		 	s[arr[i]]++;
		 	
		 }
		 cout<<ans<<endl;
	}
	

}
