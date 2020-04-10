// This problem was asked by Airbnb.

// Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

// For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.
//   2 4 8 8
// 2 4 8 6 13
// 0 2 4 8 8
// Follow-up: Can you do this in O(N) time and constant space?

#include<bits/stdc++.h>
using namespace std;

int func(int n)
{

    vector <int> a(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        return a[0];
    }
    int incl = a[0];
    int excl = 0;
    int excl_max;
    for(int i=1;i<n;i++)
    {
        excl_max = max(excl,incl);
        incl = excl + a[i];
        excl = excl_max;
    }
    
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        cout<<func(n)<<"\n";
    }
    return 0;
}