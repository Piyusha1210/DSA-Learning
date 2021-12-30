#include <iostream>
#include <stack>
using namespace std;

class que
{
public:
    stack<int> s1;
    stack<int> s2;

    void push(int x);
    void pop();
    int frontele();
    int backele();
    bool isempty();
    void printqueue();
};

void que::push(int x)
{
    s1.push(x);
    return;
}

void que::pop()
{
    if (s1.empty())
    {
        cout << "UnderFlow\n";
        return;
    }
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s2.pop();
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    return;
}

int que::frontele()
{
    if (s1.empty())
    {
        cout << "UnderFlow\n";
        return -1;
    }
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    int x = s2.top();
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    return x;
}

int que::backele()
{
    if (s1.empty())
    {
        cout << "UnderFlow\n";
        return -1;
    }
    return s1.top();
}

bool que::isempty()
{
    if (s1.empty())
    {
        return true;
    }
    return false;
}

void que::printqueue()
{
    if (s1.empty())
    {
        cout << "UnderFlow\n";
        return;
    }
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    int x = s2.top();
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
        cout<<s1.top()<<" ";
    }
    cout<<endl;
    return;
}

int main()
{
    que q;
    q.push(2);
    q.push(3);
    q.push(5);
    q.printqueue();
    cout << "front " << q.frontele() << endl;
    cout << "back " << q.backele() << endl;
    q.pop();
    q.printqueue();
    q.push(7);
    q.push(11);
    q.printqueue();
    cout << "front" << q.frontele() << endl;
    cout << "back " << q.backele() << endl;
    q.pop();
    q.printqueue();
    return 0;
}