#include <bits/stdc++.h>
using namespace std;

void topologicalSort(int n, int m, vector<vector<int>> v)
{
    map<int, set<int>> adj;
    for (int i = 0; i < v.size(); i++)
    {
        adj[v[i][0]].insert(v[i][1]);
    }
    for (auto it1 : adj)
    {
        cout << it1.first << " -> ";
        for (auto it2 : it1.second)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }

    // find In Degree
    unordered_map<int, int> inDegree;
    for (auto it1 : adj)
    {
        for (auto it2 : it1.second)
        {
            inDegree[it2]++;
        }
    }

    // insert all vertex with 0 indegree in queue.
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto it : adj[front])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return;
}

int main()
{
    int n, m, x, y;
    cout << "Enter No. of Nodes: ";
    cin >> n;
    cout << "Enter No. of Edges: ";
    cin >> m;
    cout << "Enter Edges: \n";
    vector<vector<int>> v;
    for (int i = 0; i < m; i++)
    {
        vector<int> t;
        cin >> x >> y;
        t.push_back(x);
        t.push_back(y);
        v.push_back(t);
    }
    topologicalSort(n, m, v);

    /* We can also use this for cycle detection we just have to compare size of ans(topological array) to equal to n;

    If topological array size not equal to n(no of vertices) so that it is not a valid topological sort & graph is cyclic.
     */
    return 0;
}

/*
Test Case - 1
5
5
1 2
2 3
3 4
4 5
2 4
5 1

Test Case - 2
4
4
1 2
2 3
1 4
4 3
*/