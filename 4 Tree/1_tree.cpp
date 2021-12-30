#include <iostream>
using namespace std;

class node
{
    int data;
    node *left;
    node *right;

public:
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void createTree()
{

    return;
}

int main()
{
    node *root, *t;
    t = new node(7);
    root = t;
    t = new node(3);
    root->left = t;
    t = new node(8);
    root->right = t;
    t = new node(4);
    root->left->left = t;
    return 0;
}