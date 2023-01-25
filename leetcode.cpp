#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll, ll> memoisation(int idx, int k, vector<int> &nums1, vector<int> &nums2, vector<vector<pair<ll, int>>> &dp)
{
    if (idx < 0 || k == 0)
    {
        return {0, INT_MAX};
    }

    if (dp[idx][k].first != -1)
        return dp[idx][k];

    pair<ll, ll> notPick = memoisation(idx - 1, k, nums1, nums2, dp);
    pair<ll, ll> pick = memoisation(idx - 1, k - 1, nums1, nums2, dp);
    pick.first += nums1[idx];
    if (nums2[idx] < pick.second)
        pick.second = nums2[idx];

    ll a = notPick.first * notPick.second;
    ll b = pick.first * pick.second;
    if (a >= b)
        dp[idx][k] = notPick;
    else
        dp[idx][k] = pick;

    cout << idx << " " << k << " " << dp[idx][k].first<<" "<<dp[idx][k].second<<" "<< dp[idx][k].first*dp[idx][k].second<< endl;
    return dp[idx][k];
}

long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n = nums1.size(), v = 0;
    vector<vector<pair<ll, int>>> dp(n, vector<pair<ll, int>>(k + 1, {-1, INT_MAX}));
    ll sum = 0, mini = INT_MAX;
    pair<ll, ll> ans = memoisation(n - 1, k, nums1, nums2, dp);
}