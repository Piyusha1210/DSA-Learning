#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
        // cout << v[i] << " ";
    }
    cout << endl;

    int c = 0, maxi = 0, ans = 0;

    int i = 0;
    while (i < n)
    {
        if (v[i] != 0)
            break;
        i++;
    }
    ans = max(ans, i);
    // cout << i << " " << ans << endl;

    for (; i < n; i++)
    {
        if (v[i] == 0)
            c++;
        else
        {
            maxi = max(maxi, c);
            ans = max(ans, maxi / 2 + 1);
            // cout << maxi << " " << ans << endl;
            c = 0;
        }
    }

    ans = max(ans, c);
    cout << ans << endl;
    return 0;
}

// 100010

/*

101
1110
1110
*/