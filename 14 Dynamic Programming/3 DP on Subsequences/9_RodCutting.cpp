//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int memoisation(int idx, int len, int price[], vector<vector<int>> &dp)
    {
        if(len == 0)
            return 0;
            
        if(idx <0 || len<0)
            return INT_MIN;
        
        if(dp[idx][len] != -1)
            return dp[idx][len];
            
        int notpick = memoisation(idx-1, len, price, dp);
        int pick = 0;
        if(len >= idx + 1)
        {
            pick = memoisation(idx, len-idx-1, price, dp) + price[idx];
        }
        dp[idx][len] = max(pick, notpick);
        return dp[idx][len];
    }
    
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return memoisation(n-1, n, price, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends