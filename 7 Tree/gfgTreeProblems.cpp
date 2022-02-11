#include <bits/stdc++.h>
using namespace std;

// #define queSolved 7
struct Node
{
    int data;
    Node *left, *right;
};

/*
1 Number of root to leaf paths
https://practice.geeksforgeeks.org/problems/number-of-root-to-leaf-paths/1/?category[]=Tree&category[]=Tree&problemStatus=unsolved&difficulty[]=1&page=1&query=category[]TreeproblemStatusunsolveddifficulty[]1page1category[]Tree#
void preOrderTraversal(Node* root, int h, map<int,int> &m)
{
    if(root==NULL)
        return;

    h++;
    if(root->left == NULL && root->right == NULL)
    {
        m[h]++;
    }
    preOrderTraversal (root->left, h, m);
    preOrderTraversal (root->right, h, m);
}
void pathCounts(Node *root)
{
    int h = 0;
    map<int,int> m;
    preOrderTraversal(root, h, m);
    for(auto it: m)
    {
        cout<<it.first<<" "<<it.second<<" $";
    }
}
*/

/*
2 Count Number of SubTrees having given Sum
https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1/?category[]=Tree&category[]=Tree&problemStatus=unsolved&difficulty[]=1&page=1&query=category[]TreeproblemStatusunsolveddifficulty[]1page1category[]Tree#
int postOrderTraversal(Node* root, int x, int sum, int &ans)
{
    if(root==NULL)
        return 0;
    int a = postOrderTraversal (root->left, x, sum, ans);
    int b = postOrderTraversal (root->right, x, sum, ans);
    sum = a + root->data + b;
    if(sum == x)
        ans++;
    return sum;
}

int countSubtreesWithSumX(Node* root, int X)
{
    int sum=0, ans=0;
    postOrderTraversal(root, X, sum, ans);
    return ans;
}
*/

/*
3 Count Leaves in Binary Tree
https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1/?category[]=Tree&category[]=Tree&problemStatus=unsolved&page=1&query=category[]TreeproblemStatusunsolvedpage1category[]Tree#

int countLeaves(Node* root)
{
    if(root==NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    int a = countLeaves(root->left);
    int b = countLeaves(root->right);
    return a+b;
}
*/

/*
4 Size of Binary Tree
https://practice.geeksforgeeks.org/problems/size-of-binary-tree/1/?category[]=Tree&category[]=Tree&problemStatus=unsolved&page=1&query=category[]TreeproblemStatusunsolvedpage1category[]Tree
int getSize(Node* node)
{
    if(node==NULL)
        return 0;
    
    int a = getSize(node->left);
    int b = getSize(node->right);
    return a+b+1;
}
*/

/*
5 Mirror Tree
https://practice.geeksforgeeks.org/problems/mirror-tree/1/?category[]=Tree&category[]=Tree&problemStatus=unsolved&page=1&query=category[]TreeproblemStatusunsolvedpage1category[]Tree

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        if(root==NULL)
            return;
            
        Node*temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        mirror(root->left);
        mirror(root->right);
        return;
    }
};
*/

/*
6 K distance from root
https://practice.geeksforgeeks.org/problems/k-distance-from-root/1/?category[]=Tree&category[]=Tree&problemStatus=unsolved&page=1&query=category[]TreeproblemStatusunsolvedpage1category[]Tree

void traversal(struct Node *root, vector<int>&v, int k)
{
    if(root==NULL)
        return;
        
    if(k==0)
    {
        v.push_back(root->data);
        return;
    }
    traversal(root->left, v, k-1);
    traversal(root->right, v, k-1);
}
vector<int> Kdistance(struct Node *root, int k)
{
    vector<int> v;
    traversal(root, v, k);
    return v;
}
*/

/*
7 Expression Tree
https://practice.geeksforgeeks.org/problems/expression-tree/1/?category[]=Tree&category[]=Tree&problemStatus=unsolved&page=1&query=category[]TreeproblemStatusunsolvedpage1category[]Tree#

class Solution{
  public:
    int evalTree(node* root) {
        if(root->left == NULL && root->right == NULL)
        {
            int t=0;
            for(int i=0; i < root->data.size(); i++)
            {
                t *= 10;
                t += (root->data[i]-48);
            }
            return t;
        }
            
        int a = evalTree(root->left);
        int b = evalTree(root->right);
        if(root->data[0] == '+')
            return a+b;
        else if(root->data[0] == '-')
            return a-b;
        else if(root->data[0] == '*')
            return a*b;
        else if(root->data[0] == '/')
            return a/b;
    }
};
*/

/*
8 Odd even level difference 
https://practice.geeksforgeeks.org/problems/odd-even-level-difference/1/?category[]=Tree&category[]=Tree&problemStatus=unsolved&page=1&query=category[]TreeproblemStatusunsolvedpage1category[]Tree

class Solution{
  public:
    void traversal(struct Node *root, int &even, int &odd, int k)
    {
        if(root==NULL)
            return;
        
        if(k%2 == 0)
            even += root->data;
        else
            odd += root->data;
            
        traversal(root->left, even, odd, k+1);
        traversal(root->right, even, odd, k+1);
        return;
    }
    
    int getLevelDiff(Node *root)
    {
       int diff=0, even=0,odd=0;
       traversal(root, even, odd, 1);
       diff = odd - even;
       return diff;
    }
};
*/