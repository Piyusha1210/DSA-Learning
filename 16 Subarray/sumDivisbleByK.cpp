#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        int sum = 0, r, ans = 0;
        mp[0] = 1;
        /*
        Intitution: find prefix sum if sum[i] % k == sum[j] % k then it will setisfy the require condn so we make group of sum with same remainder & count all possible pairs among them

        mp[0] = 1; because sum with remainder zero can make pair with themselves only means 0...i
        */
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            r = (sum % k + k) % k; // To avoid Negative remainders
            ans += mp[r];
            mp[r]++;
        }
        return ans;
    }
};