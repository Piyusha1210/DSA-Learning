#include <bits/stdc++.h>
using namespace std;
#define queSolved 3

/*
1 
class Solution
{
public:
    vector<int> duplicates(int arr[], int n)
    {
        vector<int> v;
        set<int> s;
        sort(arr, arr + n);
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
                s.insert(arr[i]);
        }
        if (s.empty())
            s.insert(-1);
        for (auto it : s)
        {
            v.push_back(it);
        }
        return v;
    }
};
*/

/*
2 The Celebrity Problem
https : // practice.geeksforgeeks.org/problems/the-celebrity-problem/1/?category[]=Arrays&category[]=Arrays&difficulty[]=1&page=1&sortBy=submissions&query=category[]Arraysdifficulty[]1page1sortBysubmissionscategory[]Arrays#

class Solution
{
public:
    int celebrity(vector<vector<int>> &M, int n)
    {
        for (int j = 0; j < n; j++)
        {
            int c = 0;
            for (int i = 0; i < n; i++)
            {
                if (M[i][j] == 1)
                    c++;
            }
            if (c == n - 1)
            {
                c = 0;
                for (int i = 0; i < n; i++)
                {
                    if (M[j][i] == 1)
                        c++;
                }
                if (c == 0)
                    return j;
            }
        }
        return -1;
    }
};
*/

/*
3 Smallest Positive missing number
https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1/?category[]=Arrays&category[]=Arrays&difficulty[]=1&page=1&sortBy=submissions&query=category[]Arraysdifficulty[]1page1sortBysubmissionscategory[]Arrays

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        int miss = 1;
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0 && arr[i+1] != arr[i])
            {
                if (arr[i] == miss)
                    miss++;
                else
                    return miss;
            }
        }
        return miss;
    }
};
*/