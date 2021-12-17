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

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        return;
    }
}

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
    return;
}

bool search(node *head, int val)
{
    while (head != NULL)
    {
        if (head->data == val)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

void deleteAtHead(node *&head)
{   node *toDelete=head;
    head=head->next;
    delete toDelete;
}
void deleteAtTail(node *&head)
{
    node*temp=head;
    while (temp->next!=NULL)
    {
        
    }
    
}

void printlist(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
    return;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 5);
    printlist(head);
    insertAtTail(head, 7);
    printlist(head);
    insertAtHead(head, 3);
    printlist(head);
    return 0;
}