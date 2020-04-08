// This problem was asked by Google.

// A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

// Given the root to a binary tree, count the number of unival subtrees.

// For example, the following tree has 5 unival subtrees:

//    0
//   / \
//  1   0
//     / \
//    1   0
//   / \
//  1   1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *Left;
    Node *Right;
    int data;
    Node(int x)
    {
        data = x;
        Left = NULL;
        Right = NULL;
    }
};

Node *creation(int n)
{
    Node *arr[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = new Node(1000);
    }
    cout << "Enter the heirarchy of the tree: " << endl;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        if (c == 'L')
        {
            arr[a]->Left = arr[b];
        }
        else
        {
            arr[a]->Right = arr[b];
        }
    }
    cout << "Enter the data in the tree: " << endl;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        arr[i]->data = k;
    }
    return arr[1];
}
int unival(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->Left == NULL && root->Right == NULL)
    {
        return 1;
    }
    int ans = unival(root->Left) + unival(root->Right);
    if (root->Left == NULL)
    {
        if (root->Right->data == root->data)
        {
            ans++;
            return ans;
        }
    }
    else if (root->Right == NULL)
    {
        if (root->Left->data == root->data)
        {
            ans++;
            return ans;
        }
    }
    if (root->Left->data == root->Right->data && root->data == root->Right->data)
    {
        ans++;
    }
    return ans;
}
int main()
{
    Node *arr[1001];
    int n;
    cin >> n;
    Node *root = creation(n);
    cout << "The number of univals in the tree are: " << unival(root);
    return 0;
}