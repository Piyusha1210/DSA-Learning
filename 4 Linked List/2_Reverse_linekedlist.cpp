#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

node *reverse(node *head, int k)
{
    node *prev=NULL, *curr=head, *next;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        
    }
    head = prev;
    return head;
}

int main()
{

    return 0;
}