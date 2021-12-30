#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue
{
public:
    node *front, *back;
    queue()
    {
        front = NULL;
        back = NULL;
    }
    void push(int x);
    void pop();
    int frontele();
    int backele();
    bool isempty();
    void printqueue();
};

void queue::push(int x)
{
    node *n = new node(x);
    if (front == NULL)
    {
        back = n;
        front = n;
        return;
    }
    back->next = n;
    back = n;
    return;
}

void queue::pop()
{
    if (front == NULL)
    {
        cout << "UnderFlow\n";
        return;
    }
    node *todelete = front;
    front = front->next;
    delete (todelete);
    return;
}

int queue::frontele()
{
    if (front == NULL)
    {
        cout << "UnderFlow\n";
        return -1;
    }
    return front->data;
}

int queue::backele()
{
    if (front == NULL)
    {
        cout << "UnderFlow\n";
        return -1;
    }
    return back->data;
}

bool queue::isempty()
{
    if (front == NULL)
    {
        return true;
    }
    return false;
}

void queue::printqueue()
{
    if (front == NULL)
    {
        cout << "Empty Queue\n";
        return;
    }
    node *t = front;
    while (t != NULL)
    {
        cout << t->data << " ";
        t=t->next;
    }
    cout << endl;
    return;
}

int main()
{
    queue q;
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
    cout << "front " << q.frontele() << endl;
    cout << "back " << q.backele() << endl;
    q.pop();
    q.printqueue();
    return 0;
}