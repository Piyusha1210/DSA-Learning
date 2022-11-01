//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int memoisation(int idx, int W, int wt[], int val[], vector<vector<int>> &dp)
    {
        if(W == 0 || idx < 0)
            return 0;
        
        if(dp[idx][W] != -1)
            return dp[idx][W];
        
        int notpick = memoisation(idx-1, W, wt, val, dp);
        int pick = 0;
        if(wt[idx] <= W)
            pick = memoisation(idx-1, W-wt[idx], wt, val, dp) + val[idx];
        
        dp[idx][W] = max(pick, notpick);
        return dp[idx][W];
    }
    
    int tabulation(int n, int W, int wt[], int val[])
    {
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        if(wt[0] <= W)
            dp[0][wt[0]] = val[0];
        
        for(int i = 1; i<n; i++)
        {
            for(int j = 0; j <= W; j++)
            {
                int notpick = dp[i-1][j];
                int pick = 0;
                if(wt[i] <= j)
                    pick = dp[i-1][j-wt[i]] + val[i];
                dp[i][j] = max(pick, notpick);
            }
        }
        return dp[n-1][W];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    {
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        // return memoisation(n-1, W, wt, val, dp);
        return tabulation(n, W, wt, val);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends