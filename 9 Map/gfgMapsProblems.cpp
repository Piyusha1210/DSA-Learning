#include <bits/stdc++.h>
using namespace std;

// #define queSolved 2

/*
1 Multimap Operations
https://practice.geeksforgeeks.org/problems/multimap-operations/1/?category[]=Map&category[]=Map&difficulty[]=0&page=1&query=category[]Mapdifficulty[]0page1category[]Map
multimap<int, int> multimapInsert(int arr[], int n)
{
    multimap<int, int> mp;
    // Insert arr[i] as key and i as value in the multimap
    for (int i = 0; i < n; i++)
    {
        mp.insert({arr[i], i});
    }
    return mp;
}
void multimapDisplay(multimap<int, int> mp)
{
    // Print the keys and value pairs in new line
    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }
}
void multimapErase(multimap<int, int> &mp, int x)
{
    // If and else condition to erase x from the multimap
    if (mp.find(x) != mp.end())
    {
        cout << "erased " << x;
        mp.erase(x);
    }
    else
    {
        cout << "not found";
    }
    cout << endl;
}
*/

/*
2 Maximum difference Indexes
https://practice.geeksforgeeks.org/problems/maximum-difference-10429/1/?page=1&difficulty[]=0&status[]=unsolved&category[]=Map&sortBy=submissions#

class Solution{
    public:
    int maxDiffIndex(int A[], int N)
    {
        map<int, pair<int,int>> mp;
        
        for(int i=0; i<N; i++)
        {
            if(mp.find(A[i]) == mp.end())
            {
                mp[A[i]] = {i,i};
            }
            else
            {
                mp[A[i]].second = i;
            }
        }
        int max=0;
        for (auto it : mp)
        {
            int d = it.second.second - it.second.first;
            if(d>max)
                max = d;
        }
        return max;
    }
};
*/