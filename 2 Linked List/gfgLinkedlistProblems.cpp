#include <bits/stdc++.h>
using namespace std;
#define MAX 20

// #define queSolved 3

// // 1 Linked List Matrix
// // https://practice.geeksforgeeks.org/problems/linked-list-matrix/1/?category[]=Linked%20List&category[]=Linked%20List&difficulty[]=0&page=1&query=category[]Linked%20Listdifficulty[]0page1category[]Linked%20List#
// struct Node
// {
//     int data;
//     Node *right, *down;
//     Node(int x)
//     {
//         data = x;
//         right = NULL;
//         down = NULL;
//     }
// };
// void twoDLinkedlist(int mat[MAX][MAX], int n, int i, int j, Node *&head)
// {
//     if (i == n - 1 || j == n - 1)
//         return;
//     if (i + 1 < n)
//     {
//         Node *temp = new Node(mat[i + 1][j]);
//         head->right = temp;
//         twoDLinkedlist(mat, n, i + 1, j, head->right);
//     }
//     if (j + 1 < n)
//     {
//         Node *temp = new Node(mat[i][j + 1]);
//         head->down = temp;
//         twoDLinkedlist(mat, n, i, j + 1, head->down);
//     }
//     return;
// }
// Node *constructLinkedMatrix(int mat[MAX][MAX], int n)
// {
//     Node *head = new Node(mat[0][0]);
//     int i = 0, j = 0;
//     twoDLinkedlist(mat, n, i, j, head);
//     return head;
// }

// 2 linked list of strings forms a palindrome
// https://practice.geeksforgeeks.org/problems/linked-list-of-strings-forms-a-palindrome/1/?category[]=Linked%20List&category[]=Linked%20List&difficulty[]=0&page=1&query=category[]Linked%20Listdifficulty[]0page1category[]Linked%20List
// struct Node
// {
//     string data;
//     Node *next;

//     Node(int x)
//     {
//         data = x;
//         next = NULL;
//     }
// };
// bool compute(Node *root)
// {
//     string s;
//     while (root)
//     {
//         for (int i = 0; i < root->data.size(); i++)
//         {
//             s.push_back(root->data[i]);
//         }
//         root = root->next;
//     }
//     for (int i = 0, j = s.size() - 1; i < j; i++, j--)
//     {
//         if (s[i] != s[j])
//             return false;
//     }
//     return true;
// }

// 3 Merge 2 sorted linked list in reverse order
// https://practice.geeksforgeeks.org/problems/merge-2-sorted-linked-list-in-reverse-order/1/?category[]=Linked%20List&category[]=Linked%20List&difficulty[]=0&page=1&query=category[]Linked%20Listdifficulty[]0page1category[]Linked%20List
// struct Node
// {
//     int data;
//     Node *next;
// };
// struct Node *mergeResult(Node *node1, Node *node2)
// {
//     Node *head = NULL, *temp = NULL;
//     while (node1 && node2)
//     {
//         if (node1->data < node2->data)
//         {
//             head = node1;
//             node1 = node1->next;
//             head->next = temp;
//             temp = head;
//         }
//         else
//         {
//             head = node2;
//             node2 = node2->next;
//             head->next = temp;
//             temp = head;
//         }
//     }
//     while (node1)
//     {
//         head = node1;
//         node1 = node1->next;
//         head->next = temp;
//         temp = head;
//     }
//     while (node2)
//     {
//         head = node2;
//         node2 = node2->next;
//         head->next = temp;
//         temp = head;
//     }
//     return head;
// }