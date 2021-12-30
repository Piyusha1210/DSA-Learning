#include <iostream>
using namespace std;
#define n 10
class queue
{
    int *arr;
    int front, back;

public:
    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
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
    if (back == n - 1)
    {
        cout << "OverFlow\n";
        return;
    }
    back++;
    arr[back] = x;
    if (front == -1)
    {
        front = 0;
    }
    return;
}

void queue::pop()
{
    if (back == n - 1 || front > back)
    {
        cout << "UnderFlow\n";
        return;
    }
    front++;
    return;
}

int queue::frontele()
{
    if (back == n - 1 || front > back)
    {
        cout << "UnderFlow\n";
        return -1;
    }
    return arr[front];
}

int queue::backele()
{
    if (back == n - 1 || front > back)
    {
        cout << "UnderFlow\n";
        return -1;
    }
    return arr[back];
}

bool queue::isempty()
{
    if (back == n - 1 || front > back)
    {
        return true;
    }
    return false;
}

void queue::printqueue()
{
    if (front == -1)
    {
        cout << "Empty Queue\n";
        return;
    }
    int i = front;
    while (i <= back)
    {
        cout << arr[i] << " ";
        i++;
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