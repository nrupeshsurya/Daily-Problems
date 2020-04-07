#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node (int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* creation(int n)
{
    Node* arr[n+1];
    for(int i=0;i<n+1;i++)
    {
        arr[i] = new Node(1000);
    }

    for(int i=0;i<n;i++)
    {
        int a,b;
        char c;
        cin>>a>>b>>c;

        if(c=='L')
        {
            arr[a]->left = arr[b];
        }
        else
        {
            arr[a]->right = arr[b];
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i]->data;
    }
    Node* root = arr[1];
    return root;
}

int main()
{
    int n;
    cin>>n;
    Node* root = creation(n);
    return 0;
}