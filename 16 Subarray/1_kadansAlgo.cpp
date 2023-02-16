#include <bits/stdc++.h>
using namespace std;

int kadanAlgoMaxSum(vector<int> &a)
{
    int sum = 0, currSum = 0, ans = INT_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        currSum += a[i];
        ans = max(ans, currSum);
        if (currSum < 0)
            currSum = 0;
        cout << currSum << " ";
    }
    return ans;
}

int kadanAlgoMinSum(vector<int> &a)
{
    int sum = 0, currSum = 0, ans = INT_MAX;
    for (int i = 0; i < a.size(); i++)
    {
        currSum += a[i];
        ans = min(ans, currSum);
        if (currSum > 0)
            currSum = 0;
        cout << currSum << " ";
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << kadanAlgoMaxSum(a) << endl;
    cout << kadanAlgoMinSum(a) << endl;
    return 0;
}
/*
7
2 5 -3 5 -7 2 4

3
-1 -2 -3
*/