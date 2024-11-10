#include<bits/stdc++.h>
using namespace std;

class Pointer {
    int prev;
    int next;
    Pointer(int prev, int next){
        prev = prev;
        next = next;
    }
}
unordered_map<int, pointer> mp;


/**
 * This question is similar to LRU cache and can be implement more efficiently with doubly linked list and unordered_map
*/ 

void removeNode(int val)
{

    int prev = mp[val].prev;
    int nxt = mp[val].next;

    mp[prev].second = nxt;
    mp[next].prev = prev;
    mp[val].second = -1;
}

void solve(Optional<Integer> input)
{
    int ans;
    if(input == NULL)
    {
        ans = mp[-1].second;
        removeNode(ans);
    }
    else
    {
        if(mp[input].second == -1)
        {
            ans = NULL;
        }
        else
        {
            ans = input;
            removeNode(input);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    
    mp[-1] = new Pointer(-1, 0);
    int n = 1e6;

    mp[-1] = new Pointer(-1, 0);
    for(int i = 0; i < n; i++)
    {
        mp[i] = new Pointer(i-1, i+1);
    }

    solve(5);
    solve();

    return 0;
}