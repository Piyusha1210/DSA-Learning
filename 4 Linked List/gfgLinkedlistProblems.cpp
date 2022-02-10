#include <bits/stdc++.h>
using namespace std;
#define MAX 20

#define queSolved 12

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

/*
6 Delete without head pointer
https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1/?category[]=Linked%20List&category[]=Linked%20List&difficulty[]=0&page=1&query=category[]Linked%20Listdifficulty[]0page1category[]Linked%20List
class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
        if(del == NULL || del->next == NULL)
            return;
        Node *temp = del->next;
        del->data = del->next->data;
        del->next = del->next->next;
        delete temp;
    }

};
*/

/*
7 Nth node from end of linked list
https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1/?category[]=Linked%20List&category[]=Linked%20List&problemStatus=unsolved&difficulty[]=0&page=1&query=category[]Linked%20ListproblemStatusunsolveddifficulty[]0page1category[]Linked%20List#

int getNthFromLast(Node *head, int n)
{
    Node* temp=head;
    int Tnodes=0;
    while(temp)
    {
        Tnodes++;
        temp = temp->next;
    }
    temp = head;
    if(n>Tnodes)
        return -1;
    while(temp)
    {
        if(Tnodes == n)
        {
            return temp->data;
        }
        Tnodes--;
        temp = temp->next;
    }
}
*/

/*
8 Remove duplicate element from sorted Linked
https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1/?category[]=Linked%20List&category[]=Linked%20List&problemStatus=unsolved&difficulty[]=0&page=1&query=category[]Linked%20ListproblemStatusunsolveddifficulty[]0page1category[]Linked%20List

Node *removeDuplicates(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->next == NULL)
            break;
        else if (temp->data == temp->next->data)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
*/

/*
9 Find length of Loop
https://practice.geeksforgeeks.org/problems/find-length-of-loop/1/?category[]=Linked%20List&category[]=Linked%20List&problemStatus=solved&page=1&query=category[]Linked%20ListproblemStatussolvedpage1category[]Linked%20List

int countNodesinLoop(struct Node *head)
{
    unordered_set<Node *> s;
    int ans=1;
    Node* temp = head, *start=NULL, *end=NULL;
    while(temp)
    {
        if(s.find(temp->next)!=s.end())
        {
            start = temp->next;
            end = temp;
            break;
        }
        else
        {
            s.insert(temp);
        }
        temp = temp->next;
    }
    if(start==NULL)
        return 0;
    while(start!=end)
    {
        ans++;
        start= start->next;
    }
    return ans;
}
*/

/*
10 Detect Loop in linked list
https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1/?category[]=Linked%20List&category[]=Linked%20List&problemStatus=unsolved&difficulty[]=0&page=1&sortBy=submissions&query=category[]Linked%20ListproblemStatusunsolveddifficulty[]0page1sortBysubmissionscategory[]Linked%20List#
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        set<Node *>s;
        while(head)
        {
            if(s.find(head)!=s.end())
                return true;
            else
                s.insert(head);
            head = head->next;
        }
        return false;
    }
};
*/

/*
11 Finding middle element in a linked list
https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1/?category[]=Linked%20List&category[]=Linked%20List&problemStatus=unsolved&difficulty[]=0&page=1&sortBy=submissions&query=category[]Linked%20ListproblemStatusunsolveddifficulty[]0page1sortBysubmissionscategory[]Linked%20List
class Solution{
    public:
    int getMiddle(Node *head)
    {
        int c=0,i=0;
        Node *temp = head;
        while(temp)
        {
            c++;
            temp = temp->next;
        }
        temp = head;
        while(temp && i<c/2)
        {
            i++;
            temp = temp->next;
        }
        return temp->data;
    }
};
*/

/*
12 Split a Circular Linked List into two halves
https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1/?category[]=Linked%20List&category[]=Linked%20List&problemStatus=unsolved&difficulty[]=0&page=1&query=category[]Linked%20ListproblemStatusunsolveddifficulty[]0page1category[]Linked%20List#

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    int i=1,c=1;
    Node *temp = head->next;
    Node *head1=NULL, *head2=NULL;
    Node *tail1=NULL, *tail2=NULL;
    while(temp != head)
    {
        c++;
        temp = temp->next;
    }

    if(c==1)
    {
        head1=head;
        head2=head;
        *head1_ref = head1;
        *head2_ref = head2;
        return;
    }

    temp = head;
    head1 = head;
    while(i <= (c + 1) / 2)
    {
        tail1 = temp;
        temp = temp->next;
        i++;
    }
    tail1->next = head1;
    head2 = temp;
    while(temp != head)
    {
        tail2 = temp;
        temp = temp->next;
    }
    tail2->next = head2;

    *head1_ref = head1;
    *head2_ref = head2;
}
*/