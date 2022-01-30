#include <bits/stdc++.h>
using namespace std;
#define MAX 20

#define queSolved 4

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

/*
 1 Linked List Matrix
 https://practice.geeksforgeeks.org/problems/linked-list-matrix/1/?category[]=Linked%20List&category[]=Linked%20List&difficulty[]=0&page=1&query=category[]Linked%20Listdifficulty[]0page1category[]Linked%20List#
struct Node
{
    int data;
    Node *right, *down;
    Node(int x)
    {
        data = x;
        right = NULL;
        down = NULL;
    }
};
void twoDLinkedlist(int mat[MAX][MAX], int n, int i, int j, Node *&head)
{
    if (i == n - 1 || j == n - 1)
        return;
    if (i + 1 < n)
    {
        Node *temp = new Node(mat[i + 1][j]);
        head->right = temp;
        twoDLinkedlist(mat, n, i + 1, j, head->right);
    }
    if (j + 1 < n)
    {
        Node *temp = new Node(mat[i][j + 1]);
        head->down = temp;
        twoDLinkedlist(mat, n, i, j + 1, head->down);
    }
    return;
}
Node *constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    Node *head = new Node(mat[0][0]);
    int i = 0, j = 0;
    twoDLinkedlist(mat, n, i, j, head);
    return head;
}
*/

/*
2 linked list of strings forms a palindrome
https://practice.geeksforgeeks.org/problems/linked-list-of-strings-forms-a-palindrome/1/?category[]=Linked%20List&category[]=Linked%20List&difficulty[]=0&page=1&query=category[]Linked%20Listdifficulty[]0page1category[]Linked%20List

bool compute(Node *root)
{
    string s;
    while (root)
    {
        for (int i = 0; i < root->data.size(); i++)
        {
            s.push_back(root->data[i]);
        }
        root = root->next;
    }
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
            return false;
    }
    return true;
}
*/

/*
3 Merge 2 sorted linked list in reverse order
https://practice.geeksforgeeks.org/problems/merge-2-sorted-linked-list-in-reverse-order/1/?category[]=Linked%20List&category[]=Linked%20List&difficulty[]=0&page=1&query=category[]Linked%20Listdifficulty[]0page1category[]Linked%20List
struct Node *mergeResult(Node *node1, Node *node2)
{
    Node *head = NULL, *temp = NULL;
    while (node1 && node2)
    {
        if (node1->data < node2->data)
        {
            head = node1;
            node1 = node1->next;
            head->next = temp;
            temp = head;
        }
        else
        {
            head = node2;
            node2 = node2->next;
            head->next = temp;
            temp = head;
        }
    }
    while (node1)
    {
        head = node1;
        node1 = node1->next;
        head->next = temp;
        temp = head;
    }
    while (node2)
    {
        head = node2;
        node2 = node2->next;
        head->next = temp;
        temp = head;
    }
    return head;
}
*/

/*
4 Linked List Length Even or Odd?
https://practice.geeksforgeeks.org/problems/linked-list-length-even-or-odd/1/?category[]=Linked%20List&category[]=Linked%20List&page=1&query=category[]Linked%20Listpage1category[]Linked%20List

int isLengthEvenOrOdd(struct Node* head)
{
    int c = 0;
    Node* temp = head;
    while(temp)
    {
        c++;
        temp = temp->next;
    }
    if(c%2 == 0)
        return 0;
    return 1;
}
*/

/*
5 Rearrange a linked list
https://practice.geeksforgeeks.org/problems/rearrange-a-linked-list/1/?category[]=Linked%20List&category[]=Linked%20List&difficulty[]=1&page=1&query=category[]Linked%20Listdifficulty[]1page1category[]Linked%20List#

class Solution
{
public:
    void rearrangeEvenOdd(Node *head)
    {
        Node *ehead = NULL, *ohead = NULL, *etail = NULL, *otail = NULL;
        int c = 0;
        while (head)
        {
            c++;
            if (c % 2 != 0)
            {
                if (ohead == NULL)
                {
                    ohead = head;
                    otail = head;
                }
                else
                {
                    otail->next = head;
                    otail = otail->next;
                }
            }
            else
            {
                if (ehead == NULL)
                {
                    ehead = head;
                    etail = head;
                }
                else
                {
                    etail->next = head;
                    etail = etail->next;
                }
            }
            head = head->next;
        }
        otail->next = ehead;
        head = ohead;
        if (ehead)
        {
            etail->next = NULL;
        }
        return;
    }
};
*/

class Solution
{
public:
    Node *compute(Node *head)
    {
        Node *newHead, *temp = head;
        int max= head->data;
        while(temp)
        {

        }
    }
};