#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *left;
    node *right;
    node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

node *constructTree()
{
    cout << "Enter Node Data: ";
    int data;
    cin >> data;
    node *root = new node(data);
    if (data == -1)
        return NULL;
    cout << data << " Left Node Data ";
    root->left = constructTree();

    cout << data << " Right Node Data ";
    root->right = constructTree();

    return root;
}

void levelOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    queue<node *> qu;
    qu.push(root);
    qu.push(NULL);
    while (!qu.empty())
    {
        node* front = qu.front();
        qu.pop();
        if(front == NULL)
        {
            cout<<endl;
            if(!qu.empty())
                qu.push(NULL);
            continue;
        }
        cout << front->val << " ";
        if (front->left)
            qu.push(front->left);
        
        if (front->right)
            qu.push(front->right);
    }
    return;
}

node* buildFromLevelOrderTraversal()
{

}

int main()
{
    node *root = constructTree();
    // Input - 1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1
    levelOrderTraversal(root);
    return 0;
}