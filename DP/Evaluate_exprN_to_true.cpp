#include<bits/stdc++.h>
using namespace std;



int solve(string s, int i, int j, bool isTrue)
{
	if(i>j)
	{
		return 0;
	}
	
	if(i==j)
	{
		if(isTrue==true)
		{
			return s[i]=='T';
		}
		else
		{
			return s[i] =='F';
		}
	}
	
	map<string,int> mp;
	
string temp = to_string(i)+" "+to_string(j)+" "+to_string(isTrue);
	
	if(mp.find(temp)!=mp.end())
	{
		return mp[temp];
	}
	
	int ans = 0;
	
	for(int k=i+1; i<=j-1; k=k+2)
	{
		int lt = solve(s,i,k-1,true);
		int lf = solve(s,i,k-1,false);
		int rt = solve(s,k+1,j,true);
		int rf = solve(s,k+1,j,false);
		
		if(s[k]=='&')
		{
			if(isTrue==true)
			{
				ans+=lt*rt;
			}
			else
			{
				ans+=lt*rf+lf*rt+lf*rf;
			}
		}
		else if(s[k]=='|')
		{
			if(isTrue==true)
			{
				ans+=lt*rt+lf*rt+lt*rf;	
			}
			else
			{
				ans+=lf*rf;
			}
		}
		else if(s[k]=='^')
		{
			if(isTrue==true)
			{
				ans+=lf*rt+lt*rf;
			}
			else
			{
				ans+=lt*rt+lf*rf;
			}
		}
	}
	
	return mp[temp] = ans;
}

int main()
{
	string symbols = "TTFT";
    string operators = "|&^";
    string s;
    int j = 0;
 
    for (int i = 0; i < symbols.length(); i++)
    {
        s.push_back(symbols[i]);
        if (j < operators.length())
            s.push_back(operators[j++]);
    }
     
    // We obtain the string  T|T&F^T
    int n = s.length();
	
	
	
	int ans = solve(s,0,n-1,true);
	cout<<ans<<endl;
	
	return 0;
}
