#include <bits/stdc++.h>
using namespace std;

// #define queSolved 3

// 1 Implement two stacks in an array
// https://practice.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1/?category[]=Stack&category[]=Stack&difficulty[]=0&page=1&query=category[]Stackdifficulty[]0page1category[]Stack#
// Function to push an integer into the stack1.
class twoStacks
{
    int *arr;
    int size;
    int top1, top2;

public:
    twoStacks(int n = 100)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();
};

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--)
        {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1)
            {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            }
            else if (QueryType == 2)
            {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
}
// } Driver Code Ends

// Function to push an integer into the stack1.
void twoStacks ::push1(int x)
{
    if (top1 + 1 == top2)
        return;
    top1++;
    arr[top1] = x;
}

// Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
    if (top1 + 1 == top2)
        return;
    top2--;
    arr[top2] = x;
}

// Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
    if (top1 == -1)
        return -1;
    top1--;
    return arr[top1 + 1];
}

// Function to remove an element from top of the stack2.
int twoStacks ::pop2()
{
    if (top2 == size)
        return -1;
    top2++;
    return arr[top2 - 1];
}

// { Driver Code Starts

// 2 Reverse a string using Stack
// https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1/?category[]=Stack&category[]=Stack&difficulty[]=0&page=1&query=category[]Stackdifficulty[]0page1category[]Stack#
#include <bits/stdc++.h>
using namespace std;
char *reverse(char *str, int len);
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        char str[10000];
        cin >> str;
        long long int len = strlen(str);
        char *ch = reverse(str, len);
        for (int i = 0; i < len; i++)
        {
            cout << ch[i];
        }
        cout << endl;
    }
    return 0;
}
char *reverse(char *S, int len)
{
    stack<char> st;
    for (int i = 0; i < len; i++)
    {
        st.push(S[i]);
    }
    int i = 0;
    while (!st.empty())
    {
        S[i] = st.top();
        st.pop();
        i++;
    }
    return S;
}

// 3 Delete middle element of a stack
// https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1/?category[]=Stack&category[]=Stack&difficulty[]=0&page=1&query=category[]Stackdifficulty[]0page1category[]Stack#
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int> &s, int sizeOfStack)
    {
        stack<int> p;
        int k = ceil(sizeOfStack / 2.0);
        k = sizeOfStack - k;
        for (int i = 1; i <= k; i++)
        {
            p.push(s.top());
            s.pop();
        }
        s.pop();
        while (!p.empty())
        {
            s.push(p.top());
            p.pop();
        }
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int sizeOfStack;
        cin >> sizeOfStack;

        stack<int> myStack;

        for (int i = 0; i < sizeOfStack; i++)
        {
            int x;
            cin >> x;
            myStack.push(x);
        }

        Solution ob;
        ob.deleteMid(myStack, myStack.size());
        while (!myStack.empty())
        {
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends