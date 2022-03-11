#include <bits/stdc++.h>
using namespace std;

#define queSolved 5

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

/*
3 Add Binary Strings 
https://practice.geeksforgeeks.org/problems/add-binary-strings3805/1/?page=3&difficulty[]=1&status[]=unsolved&category[]=Strings&sortBy=submissions
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    string s;
	    int a = A.size();
	    int b = B.size();
	    int c=0;
	    int i=a-1, j=b-1;
	    for(; i>=0 && j>=0; i--, j--)
	    {
	        int val = (A[i]-48) + (B[j]-48)+c;
	        if(val==0)
	        {
	            s.push_back('0');
	            c = 0;
	        }
	        else if(val == 1)
	        {
	            s.push_back('1');
	            c = 0;
	        }
	        else if(val == 2)
	        {
	            s.push_back('0');
	            c = 1;
	        }
	        else
	        {
	            s.push_back('1');
	            c = 1;
	        }
	    }
	    while(i>=0)
	    {
	       int val = (A[i]-48) + c;
	        if(val==0)
	        {
	            s.push_back('0');
	            c = 0;
	        }
	        else if(val == 1)
	        {
	            s.push_back('1');
	            c = 0;
	        }
	        else if(val == 2)
	        {
	            s.push_back('0');
	            c = 1;
	        }
	        else
	        {
	            s.push_back('1');
	            c = 1;
	        } 
	        i--;
	    }
	    while(j>=0)
	    {
	       int val = (B[j]-48) + c;
	        if(val==0)
	        {
	            s.push_back('0');
	            c = 0;
	        }
	        else if(val == 1)
	        {
	            s.push_back('1');
	            c = 0;
	        }
	        else if(val == 2)
	        {
	            s.push_back('0');
	            c = 1;
	        }
	        else
	        {
	            s.push_back('1');
	            c = 1;
	        } 
	        j--;
	    }
	    if(c==1)
	        s.push_back('1');
	    reverse(s.begin(), s.end());
	    while(s[0]=='0')
	        s.erase(s.begin());
	    return s;
	}
};
*/

/*
4 Roman Number to Integer
https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1/?page=1&difficulty[]=0&status[]=unsolved&category[]=Strings&sortBy=submissions

class Solution {
  public:
    int romanToDecimal(string &s) {
        map<char, int> map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = 0, n = s.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (map[s[i]] >= map[s[i + 1]])
            {
                ans += map[s[i]];
            }
            else
            {
                ans -= map[s[i]];
            }
        }
        ans += map[s[n - 1]];
        return ans;
    }
};
*/

/*
5 Rearrange a string
https://practice.geeksforgeeks.org/problems/rearrange-a-string4100/1/?page=4&difficulty[]=0&status[]=unsolved&category[]=Strings&sortBy=submissions#
class Solution
{
  public:
    string arrangeString(string str)
    {
        int n=0;
        for(int i=0; i<str.size(); i++)
        {
            if(str[i]>=48 && str[i]<=57)
            {
                n+=(str[i]-48);
                str.erase(str.begin()+i);
                i--;
            }
        }
        int k = str.size();
        sort(str.begin(), str.end());
        
        while(n)
        {
            str.insert(str.begin()+k, char(n%10 + 48));
            n/=10;
        }
        return str;
        
    }
};
*/