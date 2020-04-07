#include<bits/stdc++.h>
using namespace std;

int func(string s)
{
    int sizex = s.size();
    int a[sizex+1];
    a[0]=1;
    a[1]=1;
    if(s[0]=='0')
    {
        return 0;
    }
    for (int i = 2; i <= sizex ; i++)
    {
        a[i]=0;
        if(s[i-1]>'0')
        {
            a[i]=a[i-1];
        }
        if(s[i-2]=='1'||(s[i-2]=='2'&&s[i-1]<'7'))
        {
            a[i]+=a[i-2];
        }
    }
    return a[sizex];
}

int main()
{
    string s;
    cin>>s;
    cout<<func(s);
    return 0;
}