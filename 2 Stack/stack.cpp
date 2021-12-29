#include <iostream>
using namespace std;
#define n 10

class stack
{
    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int x);
    int pop();
    int peek();
    bool isempty();
    bool isfull();
    void printStack();
};
void stack::push(int x)
{
    if (top == n - 1)
    {
        cout << "Stack Overflow\n";
        return;
    }
    top++;
    arr[top] = x;
}

int stack::pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow\n";
        return -1;
    }
    return arr[top--];
}

int stack::peek()
{
    if (top == -1)
    {
        cout << "Stack Underflow\n";
        return -1;
    }
    return arr[top];
}

bool stack::isempty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

bool stack::isfull()
{
    if (top == n - 1)
    {
        return true;
    }
    return false;
}
void stack::printStack()
{
    if (top == -1)
    {
        cout << "Empty Stack\n";
        return;
    }
    int i = top;
    while (i >= 0)
    {
        cout << arr[i] << " ";
        i--;
    }
    cout << endl;
    return;
}
int main()
{
    stack st;
    st.push(2);
    st.push(3);
    st.push(5);
    st.printStack();
    cout << "Pop " << st.pop() << endl;
    cout << "Peek " << st.peek() << endl;
    st.printStack();
    st.push(7);
    st.push(11);
    st.printStack();
    cout << "Pop " << st.pop() << endl;
    cout << "Peek " << st.peek() << endl;
    st.printStack();
    return 0;
}