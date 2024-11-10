#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll V, E;
    cin >> V >> E;

    vector<pair<ll, ll>> adj[V];

    for (ll i = 0; i < E; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    ll ans = INT_MIN;
    ll sum;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> visited(V, 0);

    for (ll i = 0; i < V; i++)
    {
        if (visited[i])
            continue;

        sum = 0;
        pq.push({0, i});

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            ll node = it.second;
            ll wt = it.first;

            if (visited[node] == 1)
                continue;

            visited[node] = 1;
            sum += wt;

            for (auto it : adj[node])
            {
                ll adjNode = it.first;
                ll edW = it.second;

                if (!visited[adjNode])
                    pq.push({edW, adjNode});
            }
        }
        ans = max(ans, sum);
    }

    cout << ans;
    return 0;
}