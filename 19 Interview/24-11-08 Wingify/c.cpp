#include<bits/stdc++.h>
using namespace std;

void recursion(int n, int o, int c, string t, vector<string> &ans)
{
    if(c == n)
    {
        ans.push_back(t);
        return;
    }

    if(o < n)
    {
        t.push_back('(');
        recursion(n, o+1, c, t, ans);
        t.pop_back();
    }
    if(c < o)
    {
        t.push_back(')');
        recursion(n, o, c+1, t, ans);
        t.pop_back();
    }
    return;
}

int main(int argc, char const *argv[])
{
    int n = 4;
    int o = 0, c = 0;
    string t;
    vector<string> ans;
    recursion(n, o, c, t, ans);
    
    for(int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}