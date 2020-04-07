// Good morning! Here's your coding interview problem for today.

// This problem was asked by Google.

// An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.

// If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and dereference_pointer functions that converts between nodes and memory addresses.


#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* npx;
    int data;
    Node(int x){
        npx = NULL;
        data =x;
    }
};
int sizex=0;

Node* xorfunc(Node* a,Node* b)
{
    return (Node*)((uintptr_t)a^(uintptr_t)b);
}

void add(Node** ref,int x)
{
    Node* temp = new Node(x);
    temp->npx = xorfunc(*ref,NULL);
    if(*ref!=NULL)
    {
        Node* next = xorfunc((*ref)->npx,NULL);
        (*ref)->npx = xorfunc(temp,next);
    }
    *ref = temp;
    sizex++;
}
void printlist(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next;
    while (curr!=NULL)
    {
        cout<<curr->data<<" ";
        next = xorfunc(prev,curr->npx);
        prev = curr;
        curr = next;
    }
}
void getx(Node* head,int x)
{
    Node* curr = head;
    Node* prev = NULL;
    int index = sizex;
    Node* next;
    while (curr!=NULL)
    {
        if(index == x)
        {
            cout<<curr->data;
            break;
        }
        index--;
        next = xorfunc(curr->npx,prev);
        prev = curr;
        curr = next;
    }
}
int main()
{
    Node* head = NULL;
    add(&head,9);
    add(&head,8);
    add(&head,7);
    add(&head,6);
    printlist(head);
    cout<<endl;
    getx(head,3);
}