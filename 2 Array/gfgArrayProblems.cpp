#include <bits/stdc++.h>
using namespace std;

#define queSolved 5

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

/*
4 Mean of range in array
https://practice.geeksforgeeks.org/problems/mean-of-range-in-array2123/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&difficulty[]=0&page=2&query=category[]ArraysproblemStatusunsolveddifficulty[]0page2category[]Arrays

class Solution{
    public:
    vector<int> findMean(int arr[],int queries[],int n,int q)
    {
        int sum[n+1];
        sum[0]=0;
        for(int i=0; i<n; i++)
        {
            sum[i+1] = sum[i]+arr[i];
        }
        
        vector<int> v;
        for(int i=0; i<q; i+=2)
        {
            int p = sum[queries[i+1]+1] - sum[queries[i]];
            int q = (queries[i+1] - queries[i] + 1);
            v.push_back(p/q);
        }
        return v;
    }

};
*/

/*
5 First Repeating Element 
https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&difficulty[]=0&page=1&query=category[]ArraysproblemStatusunsolveddifficulty[]0page1category[]Arrays

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        unordered_map<int, int> m;
        
        for(int i=0; i<n; i++)
        {
            m[arr[i]]++;
        }
        for(int i=0; i<n; i++)
        {
            auto it = m.find(arr[i]);
            if((*it).second > 1)
                return i+1;
        }
        return -1;
    }
};
*/