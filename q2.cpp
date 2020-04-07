// This problem was asked by Uber.

// Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

// For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

// Follow-up: what if you can't use division?
#include<bits/stdc++.h>
using namespace std;

void func()
{
    vector <int> a;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin>>j;
        a.push_back(j);
    }
    vector <pair<int,int>> b(n+2,{1,1});
    for(int i=1;i<=n;i++)
    {
        b[i].first = b[i-1].first*a[i-1];
        // cout<<b[i].first<<"\n";
    }
    for(int i=n;i>=1;i--)
    {
        b[i].second = a[i-1]*b[i+1].second;
        // cout<<b[i].second<<"\n";
    }
    vector <int> ans(n,1);
    for(int i=0;i<n;i++)
    {
        ans[i]=b[i].first*b[i+2].second;
        cout<<ans[i]<<" ";
    }
}

int main()
{
    func();
    return 0;
}