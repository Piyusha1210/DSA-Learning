#include <bits/stdc++.h>
using namespace std;
// #define queSolved 2

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

/*
1 Minimum element in BST
https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1/?category[]=Binary%20Search%20Tree&category[]=Binary%20Search%20Tree&page=1&query=category[]Binary%20Search%20Treepage1category[]Binary%20Search%20Tree#
s
int minValue(Node *root)
{
    int min = -1;
    if (root == NULL)
    {
        return min;
    }
    if (root->left == NULL)
    {
        min = root->data;
        return min;
    }
    minValue(root->left);
}
*/

/*
2 Search a node in BST
https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1/?category[]=Binary%20Search%20Tree&category[]=Binary%20Search%20Tree&page=1&query=category[]Binary%20Search%20Treepage1category[]Binary%20Search%20Tree#
bool search(Node* root, int x) {
    bool ans = 0;
    if(root == NULL)
        return 0;
    // cout<<root->data<<" ";
    if(root->data == x)
        return 1;
    if(root->data > x)
        ans = search(root->left, x);
    if(root->data < x)
        ans = search(root->right, x);
    return ans;
}
*/

/*
3 Construct BST from Postorder
https://practice.geeksforgeeks.org/problems/construct-bst-from-post-order/1/?category[]=Binary%20Search%20Tree&category[]=Binary%20Search%20Tree&difficulty[]=0&page=1&query=category[]Binary%20Search%20Treedifficulty[]0page1category[]Binary%20Search%20Tree#
void createTree(Node* &root, int k)
{
    if(root == NULL)
    {
        Node *temp = new Node(k);
        root = temp;
        return;
    }
    if(root->data > k)
        createTree(root->left, k);
    if(root->data < k)
        createTree(root->right, k);
}
Node *constructTree (int post[], int size)
{
    Node *root = NULL;
    for(int i = size-1; i>=0; i--)
    {
        createTree(root, post[i]);
    }
    return root;
}
*/