#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }
    int topele = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(topele);
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int x = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, x);
}

void printStack(stack<int> st)
{
    if (st.empty())
    {
        cout << "Empty Stack\n";
        return;
    }
    while (!st.empty())
    {
        cout <<st.top() << " ";
        st.pop();
    }
    cout << endl;
    return;
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    printStack(st); // Before Reversing
    reverseStack(st); 
    printStack(st); // After Reversing
}
