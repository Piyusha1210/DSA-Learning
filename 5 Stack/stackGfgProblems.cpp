#include <bits/stdc++.h>
using namespace std;

// #define queSolved 10

/*
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
*/

/*
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
*/

/*
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
*/

/*
4 Get min at pop
https://practice.geeksforgeeks.org/problems/get-min-at-pop/1/?category[]=Stack&category[]=Stack&page=1&query=category[]Stackpage1category[]Stack#

stack<int> _push(int arr[],int n)
{
    stack<int> st;
    for(int i=0; i<n; i++)
    {
        st.push(arr[i]);
    }
    return st;
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int>s)
{
    stack<int> p;
    vector<int> v;
    int min = INT_MAX;
    while(!s.empty())
    {
        p.push(s.top());
        s.pop();
    }
    while(!p.empty())
    {
        if(p.top() < min)
            min = p.top();

        v.push_back(min);
        s.push(p.top());
        p.pop();
    }
    int n = v.size();
    for(int i=0; i<n; i++)
    {
        cout<<v[n-1-i]<<" ";
    }
}
*/

/*
5 Print Bracket Numberv
https://practice.geeksforgeeks.org/problems/print-bracket-number4058/1/?category[]=Stack&category[]=Stack&problemStatus=unsolved&difficulty[]=0&page=1&query=category[]StackproblemStatusunsolveddifficulty[]0page1category[]Stack#

class Solution{
public:
    vector<int> barcketNumbers(string S)
    {
        vector<int> v;
        stack<int> st;
        int k=1;
        for(int i=0; i<S.size(); i++)
        {
            if(S[i]=='(')
            {
                st.push(k);
                v.push_back(k);
                k++;
            }
            else if(S[i]==')')
            {
                v.push_back(st.top());
                st.pop();
            }
        }
        return v;
    }
};
*/

/*
6 Parenthesis Checker
https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1/?category[]=Stack&category[]=Stack&problemStatus=unsolved&difficulty[]=0&page=1&query=category[]StackproblemStatusunsolveddifficulty[]0page1category[]Stack#

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    // map<char,int> m = {{'(',1},{')',2},{'[',3},{']',4},{'{',5},{'}',6}};
    bool ispar(string x)
    {
        stack<char> st;
        for(int i=0; i<x.size(); i++)
        {
            if(x[i]=='(' || x[i]=='[' || x[i]=='{')
                st.push(x[i]);
            else
            {
                if(st.empty())
                    return false;
                else if(x[i]==')' && st.top()=='(')
                    st.pop();
                else if(x[i]==']' && st.top()=='[')
                    st.pop();
                else if(x[i]=='}' && st.top()=='{')
                    st.pop();
                else
                    return false;
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};
*/

/*
7 Reversing the equation
https://practice.geeksforgeeks.org/problems/reversing-the-equation2205/1/?category[]=Stack&category[]=Stack&problemStatus=unsolved&difficulty[]=0&page=1&query=category[]StackproblemStatusunsolveddifficulty[]0page1category[]Stack

class Solution
{
  public:
    string reverseEqn (string s)
    {
        stack<string> st;
        string t,p;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            {
                st.push(t);
                t.erase();
                t.push_back(s[i]);
                st.push(t);
                t.erase();
            }
            else
            {
                t.push_back(s[i]);
            }
        }
        st.push(t);
        t.erase();
        while(!st.empty())
        {
            t = st.top();
            p.append(t);
            st.pop();
        }
        return p;
    }
};
*/

/*
8 String Manipulation
https://practice.geeksforgeeks.org/problems/string-manipulation3706/1/?page=1&difficulty[]=0&category[]=Stack&sortBy=submissions

class Solution{
    public:
    int removeConsecutiveSame(vector <string > v)
    {
        stack<string> st;
        for(int i=0; i<v.size(); i++)
        {
            if(st.size()>0 && st.top()==v[i])
            {
                st.pop();
            }
            else
            {
                st.push(v[i]);
            }
        }
        int c=0;
        while(!st.empty())
        {
            c++;
            st.pop();
        }
        return c;
    }
};
*/

/*
9 Reverse First K elements of Queue
https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1/?page=1&difficulty[]=0&status[]=unsolved&category[]=Stack&sortBy=submissions

queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s1, s2;
    int i=0;
    while(i<k)
    {
        s1.push(q.front());
        q.pop();
        i++;
    }
    while(!q.empty())
    {
        s2.push(q.front());
        q.pop();
    }
    while(!s1.empty())
    {
        q.push(s1.top());
        s1.pop();
    }
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    while(!s1.empty())
    {
        q.push(s1.top());
        s1.pop();
    }
    return q;
}
*/

/*
10 Delete array elements which are smaller than next or become smaller 
https://practice.geeksforgeeks.org/problems/delete-array-elements-which-are-smaller-than-next-or-become-smaller3115/1/?page=1&difficulty[]=0&status[]=unsolved&category[]=Stack&sortBy=submissions

vector<int> deleteElement(int arr[],int n,int k)
{
    stack<int> st;
    vector<int> v;
    int i=0;
    for(; i<n && k>0;)
    {
        if(st.empty())
        {
            st.push(arr[i]);
            i++;
        }
        else if(arr[i]>st.top())
        {
            st.pop();
            k--;
        }
        else
        {
            st.push(arr[i]);
            i++;
        }
    }
    while(!st.empty())
    {
        v.push_back(st.top());
        st.pop();
    }
    reverse(v.begin(), v.end());
    for(; i<n; i++)
    {
        v.push_back(arr[i]);
    }
    return v;
}
*/