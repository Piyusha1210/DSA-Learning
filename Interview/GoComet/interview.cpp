#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    string t;
    unordered_map<string, int> mp;
    for(int i = 0; i < 10; i++)
    {
        t.push_back(s[i]);
    }
    mp[t]++;

    for(int i = 10; i < s.size(); i++)
    {
        t.erase(t[0]);
        t.push_back(s[i]);
        mp[t]++;
    }

    vector<string> ans;
    for(auto it: mp)
    {
        if(it.second > 1)
        {
            ans.push_back(it.first);
            cout << it.first<<" ";
        }
    }
    return 0;
}
