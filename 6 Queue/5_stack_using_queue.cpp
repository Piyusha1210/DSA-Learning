#include <bits/stdc++.h>
using namespace std;

void push(queue<int> &qu, int x)
{
    int sz = qu.size();
    qu.push(x);
    while (sz--)
    {
        qu.push(qu.front());
        qu.pop();
    }
}

void pop(queue<int> &qu)
{
    if (qu.empty())
        return;
    qu.pop();
}

int top(queue<int> &qu)
{
    if (qu.empty())
        return -1;
    return qu.front();
}

int main(int argc, char const *argv[])
{
    queue<int> qu;
    push(qu, 3);
    push(qu, 5);
    push(qu, 7);
    push(qu, 9);
    cout << top(qu) << " ";
    pop(qu);
    cout << top(qu) << " ";
    push(qu, 11);
    cout << top(qu) << " ";
    pop(qu);
    cout << top(qu) << " ";
    return 0;
}
