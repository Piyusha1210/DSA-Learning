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
    if (front == -1 || front > back)
    {
        cout << "UnderFlow\n";
        return;
    }
    front++;
    return;
}

int queue::frontele()
{
    if (front == -1 || front > back)
    {
        cout << "UnderFlow\n";
        return -1;
    }
    return arr[front];
}

int queue::backele()
{
    if (back == n || front > back)
    {
        cout << "UnderFlow\n";
        return -1;
    }
    return arr[back];
}

bool queue::isempty()
{
    if (front == -1 || front > back)
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
    int choice = 1, x;
    while (choice)
    {
        cout << "\n1 Push\n";
        cout << "2 Pop\n";
        cout << "3 front Element\n";
        cout << "4 Back Element\n";
        cout << "5 Print Queue\n";
        cout << "0 End Function\n";
        cin >> choice;

        if (choice == 0)
        {
            break;
        }
        else if (choice == 1)
        {
            cin >> x;
            q.push(x);
        }
        else if (choice == 2)
        {
            q.pop();
        }
        else if (choice == 3)
        {
            cout << "front " << q.frontele() << endl;
        }
        else if (choice == 4)
        {
            cout << "back " << q.backele() << endl;
        }
        else if (choice == 5)
        {
            q.printqueue();
        }
    }
    return 0;
}
/*
TestCase: 1
1 2
1 3
1 5
5
3
4
2
5
1 7
1 11
5
3
4
2
5
0

TestCase: 2
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
3
4
5
2
3
4
5
0
*/