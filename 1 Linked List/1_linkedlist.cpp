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
{
    node *toDelete = head;
    head = head->next;
    delete toDelete;
    return;
}
void deleteAtTail(node *&head)
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        head = NULL;
        return;
    }

    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *toDelete = temp->next;
    temp->next = NULL;
    delete toDelete;
    return;
}

void deleteAtKey(node *&head, int key)
{
    node *temp = head;
    if (temp->data==key)
    {
        head=temp->next;
        return;
    }
    
    while (temp->next->data != key)
    {
        temp = temp->next;
        if (temp->next == NULL)
            return;
    }

    node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    return;
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
    insertAtTail(head, 9);
    printlist(head);
    insertAtHead(head, 3);
    printlist(head);
    insertAtHead(head, 1);
    printlist(head);

    deleteAtHead(head);
    printlist(head);
    deleteAtTail(head);
    printlist(head);
    deleteAtKey(head, 5);
    printlist(head);
    deleteAtKey(head, 6);
    printlist(head);
    deleteAtKey(head, 3);
    printlist(head);
    deleteAtKey(head, 7);
    printlist(head);

    return 0;
}