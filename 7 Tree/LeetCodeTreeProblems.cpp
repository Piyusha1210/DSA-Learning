#include <bits/stdc++.h>
using namespace std;

// #define queSolved 6

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 1 Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/
class Solution
{
public:
    vector<int> v;
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorderTraversal(root->left);
        v.push_back(root->val);
        inorderTraversal(root->right);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        inorder(root);
        return v;
    }
};

// 2 Same Tree
// https://leetcode.com/problems/same-tree/submissions/
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// 3  DEEPEST LEAVES SUM
class Solution
{
public:
    vector<int> v;
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    int deepestLeavesSum(TreeNode *root)
    {
        int ans = 0;
        inorder(root);
        for (int i = 0; i < v.size(); i++)
        {
            ans += v[i];
        }
        cout << ans << endl;
    }
};

// 4 Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/
class Solution
{
public:
    bool symmetricTraversal(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;
        if (p->val != q->val)
            return false;

        return symmetricTraversal(p->left, q->right) && symmetricTraversal(p->right, q->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        TreeNode *p = root->left;
        TreeNode *q = root->right;

        return symmetricTraversal(p, q);
    }
};

// 5 104. Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution
{
public:
    int max = 0;
    void inorder(TreeNode *root, int h)
    {
        if (root == NULL)
            return;
        h++;
        inorder(root->left, h);

        if (h > max)
            max = h;

        inorder(root->right, h);
    }

    int maxDepth(TreeNode *root)
    {
        int h = 0;
        inorder(root, h);
        return max;
    }
};

// 6 108. Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

class Solution
{
public:
    void createBST(TreeNode *&root, vector<int> nums, int l, int r)
    {
        if (l > r)
            return;

        int mid = (l + r) / 2;
        TreeNode *t = new TreeNode(nums[mid]);
        root = t;
        createBST(root->left, nums, l, mid - 1);
        createBST(root->right, nums, mid + 1, r);
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *root = NULL;
        int l = 0, r = nums.size()-1;
        createBST(root, nums, l, r);
        return root;
    }
};