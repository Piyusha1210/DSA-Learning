#include<bits/stdc++.h>
using namespace std;

Class Node {
	String color; // BLUE or WHITE 
	Vector<Node> children; 
}
/*
    Que: In this question we were given a n-array tree with nodes blue and white where we want to invert nodes in such a way that no parent-child combination can have blue color need to find min no of inversion to make tree such no parent-child both has blue color.

    Solution: Here we are using DFS approach where 
    base condition ->  root == NULL return 0(inversion)
    sum of inversion in all subtree for all child of that node
    if(root->color == 'BLUE and any of it's child is blue then in that case we need to invert parent color so ans++)

*/
int countInversion(Node* root)
{
	if(root == NULL) {
		return 0;
	}

    int ans = 0;
    for(auto it: root->childred)
    {
        ans += countInversion(it);
    }

	if(root->color == "BLUE")
    {
        bool flag = false;
        for(auto it: root->children)
        {
            if(it.color == "BLUE")
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            root->color = "WHITE";
            ans++;
        }
    }
    return ans;
}

