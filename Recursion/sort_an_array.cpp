#include <bits/stdc++.h>
using namespace std;

void insert(int* arr, int n, int &val)
{
    if(n==0 || arr[n-1]<=val)
    {
        arr[n]=val;
        return;
    }

    int temp = arr[n-1];
    insert(arr,n-1,val);
    arr[n]=temp;
    return;
}

void sort(int *arr, int n)
{
    if(n==1)
    {
        return;
    }
    int val = arr[n-1];

    sort(arr,n-1);

    insert(arr, n-1, val);
    
}

int main()
{
    int n; 
    cin>>n; 
    
    int *arr = new int[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    sort(arr,n);

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}