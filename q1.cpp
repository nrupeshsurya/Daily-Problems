// This problem was recently asked by Google.

// Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

// For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

// Bonus: Can you do this in one pass?
#include<bits/stdc++.h>
using namespace std;

void fun(int n, int k)
{
    vector <int> a;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin>>j;
        a.push_back(j);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++)
    {
        if(binary_search(a.begin()+i+1,a.end(),k-a[i]))
        {
            cout<<"True"<<"\n";
            return;
        }
    }
    cout<<"False"<<"\n";
}

void mfun(int n, int k)
{
    vector <int> a;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin>>j;
        a.push_back(j);
    }
    unordered_set <int> b;
    for (int i = 0; i < n; i++)
    {
        int temp = k-a[i];
        if(b.find(temp)!=b.end())
        {
            cout<<"True"<<"\n";
            return;
        }
        b.insert(a[i]);
    }
    cout<<"False"<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        mfun(n,k);
    }
    return 0;
}