#include <bits/stdc++.h>
using namespace std;
// #define queSolved 4

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

/*
4 Find Common Nodes in two BSTs
https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1/?page=1&difficulty[]=0&status[]=unsolved&category[]=Binary%20Search%20Tree&sortBy=submissions#

class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    void Traversal (Node *root, vector<int> &v)
    {
        if(root==NULL)
            return;
        
        v.push_back(root->data);
        Traversal(root->left, v);
        Traversal(root->right, v);
        
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
        vector<int> v1, v2, v;
        Traversal(root1, v1);
        Traversal(root2, v2);
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        for(int i=0, j=0; i<v1.size() && j<v2.size(); )
        {
            if(v1[i]==v2[j])
            {
                v.push_back(v1[i]);
                i++;
                j++;
            }
            else if(v1[i]<v2[j])
                i++;
            else
                j++;
        }
        return v;
    }
};
*/

/*
5 Sum of leaf nodes in BST
https://practice.geeksforgeeks.org/problems/sum-of-leaf-nodes-in-bst/1/?page=1&difficulty[]=0&status[]=unsolved&category[]=Binary%20Search%20Tree&sortBy=submissions#

int sumOfLeafNodes(Node *r ){
    static int sum=0;
    if(r==NULL)
        return 0;
    if(r->left == NULL && r->right==NULL)
    {
        return r->data;
    }

    int a = sumOfLeafNodes(r->left);
    int b = sumOfLeafNodes(r->right);
    return a+b;
}
*/