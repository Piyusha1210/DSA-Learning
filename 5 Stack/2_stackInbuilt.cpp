#include <iostream>
#include <stack>
using namespace std;

// Reverse Stack wihtout extra space
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
    return;
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
    return;
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(4);
    st.push(6);
    cout << st.top() << endl;
    st.pop();
    st.push(8);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}