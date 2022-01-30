#include <bits/stdc++.h>
using namespace std;

// #define queSolved 2

// 1 Reverse a Doubly Linked List
// https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1/?category[]=Linked%20List&category[]=Linked%20List&difficulty[]=0&page=1&query=category[]Linked%20Listdifficulty[]0page1category[]Linked%20List
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};
Node *reverseDLL(Node *head)
{
    Node *curr = head, *temp;
    while (curr->next)
    {
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = curr->prev;
    }
    curr->next = curr->prev;
    curr->prev = NULL;
    head = curr;
    return head;
}

// 2 Rotate doubly Linked List
// https://practice.geeksforgeeks.org/problems/rotate-doubly-linked-list-by-p-nodes/1/?category[]=Linked%20List&category[]=Linked%20List&difficulty[]=0&page=1&query=category[]Linked%20Listdifficulty[]0page1category[]Linked%20List
Node *update(Node *start, int p)
{
    if (!start)
        return start;

    Node *head = start, *tail = head;
    while (tail->next)
    {
        tail = tail->next;
    }
    while (p--)
    {
        tail->next = head;
        head->prev = tail;

        tail = tail->next;
        head = head->next;

        head->prev = NULL;
        tail->next = NULL;
    }
    return head;
}
