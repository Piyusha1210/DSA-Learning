#include <bits/stdc++.h>
using namespace std;

// #define queSolved 1
struct Node
{
    int data;
    Node* left, * right;
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