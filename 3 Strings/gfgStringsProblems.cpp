#include <bits/stdc++.h>
using namespace std;

#define queSolved 2

/*
1 Implement Atoi
https://practice.geeksforgeeks.org/problems/implement-atoi/1/?category[]=Strings&category[]=Strings&problemStatus=unsolved&difficulty[]=1&page=1&sortBy=submissions&query=category[]StringsproblemStatusunsolveddifficulty[]1page1sortBysubmissionscategory[]Strings#

class Solution{
  public:
    int atoi(string s) {
        int ans = 0, t=1,flag=0;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            t*=10;
        }
        for(int i = 0; i < n; i++)
        {
            t/=10;
            if(s[i] == 45 && i==0)
            {
                flag=1;
                continue;
            }
            if(s[i]>=48 && s[i]<58)
            {
                ans += (t*(s[i]-48));
            }
            else
                return -1;
        }
        if(flag==1)
            ans*=-1;
        return ans;
    }
};
*/

/*
2 Remove Duplicates
https://practice.geeksforgeeks.org/problems/remove-duplicates3034/1/?category[]=Strings&category[]=Strings&problemStatus=unsolved&difficulty[]=0&page=1&query=category[]StringsproblemStatusunsolveddifficulty[]0page1category[]Strings#

class Solution{
public:	
		
	string removeDups(string s) 
	{
	    int n = s.size();
        unordered_set<char> set;
        for(int i=0; i<s.size(); i++)
        {
            if(set.find(s[i]) == set.end())
                set.insert(s[i]);
            else
            {
                s.erase(s.begin()+i);
                i--;
            }
        }
        return s;
	}
};
*/