#include <bits/stdc++.h>
using namespace std;

vector<int> leftAns(vector<int>& heights )
{
     vector<int> ans;
        stack<pair<int,int>> s;
        int n=heights.size();
        
        for(int i=0; i<n; i++)
        {
            if(s.size()==0)
            {
                ans.push_back(-1);
            }
            else if(s.size()>0 && s.top().first<heights[i])
            {
                ans.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first>=heights[i])
            {
                while(s.size()>0 && s.top().first>=heights[i])
                {
                    s.pop();
                }
                
                if(s.size()==0)
                {
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }
        return ans;
}

vector<int> rightAns(vector<int>& heights)
{
    vector<int> ans;
        stack<pair<int,int>> s;
        int n=heights.size();
        
        for(int i=n-1; i>=0; i--)
        {
            if(s.size()==0)
            {
                ans.push_back(n);
            }
            else if(s.size()>0 && s.top().first<heights[i])
            {
                ans.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first>=heights[i])
            {
                while(s.size()>0 && s.top().first>=heights[i])
                {
                    s.pop();
                }
                
                if(s.size()==0)
                {
                    ans.push_back(n);
                }
                else{
                    ans.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
}

int MAH(vector<int>& heights)
{
    vector<int> left = leftAns(heights);
    vector<int> right = rightAns(heights);

     vector<int> width;
        int n= heights.size();
        
        for(int i=0;i<right.size();i++)
        {
            width.push_back(right[i]-left[i]-1);
        }
        for(int i=0;i<n;i++)
        {
            width[i]=heights[i]*width[i];
        }
        int mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mx = max(mx,width[i]);
        }
        return mx;
}

int maxAreaBinary(int arr[][100], int n, int m)
{
    vector<int> v;

    for(int j=0; j<m; j++)
    {
        v.push_back(arr[0][j]);
    }

    int mx = MAH(v);

    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==0)
            {
                v[j]=0;
            }
            else{
                v[j]=v[j]+arr[i][j];
            }
        }
        mx=max(mx,MAH(v));
    }
    return mx;
}

int main()
{
    int arr[100][100];

    int n,m;

    cin>>n>>m;
    

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
        }
    }

    int ans = maxAreaBinary(arr,n,m);

    cout<<"Max Area:"<<" "<<ans<<endl;


    return 0;
}