#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid1(m, vector<int>(n)), grid2(m, vector<int>(n));
    map<pair<int, int>, int> rateOfInfection;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid1[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid2[i][j];
        }
    }

    int ans = calcluateMinimumTimeToCompromised(m, n, grid1, grid2);
    cout << ans << endl;
    return 0;
}


int calcluateMinimumTimeToCompromised(int m, int n, vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<bool>> visited(m, vector<bool>(n));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid1[i][j] == 2) {
                pq.push({grid2[i][j], i, j});
                visited[i][j] = true;
            }
        }
    }

    int ans = 0;

    while(!pq.empty()) {
        vector<int> top = pq.top();
        pq.pop();

        if()

        int t = top[0], i = top[1], j = top[2];
        int compromiseTime = 0;
        if(checkIndex(i-1, j, m, n) || visited[i-1][j] || grid1[i-1][j] == 1) {
            compromiseTime = t + grid2[i-1][j];
            ans = max(ans, compromiseTime)
            pq.push({, i-1, j})
            visited[i-1][j] = true;
        }
        if(checkIndex(i+1, j, m, n) || visited[i+1][j] || grid1[i+1][j] == 1) {
            compromiseTime = t + grid2[i+1][j];
            ans = max(ans, compromiseTime)
            pq.push({compromiseTime, i+1, j})
            visited[i+1][j] = true;
        }
        if(checkIndex(i, j-1, m, n) || visited[i][j-1] || grid1[i][j-1] == 1) {
            compromiseTime = t + grid2[i][j11];
            ans = max(ans, compromiseTime)
            pq.push({compromiseTime, i, j-1})
            visited[i][j-1] = true;
        }
        if(checkIndex(i, j+1, m, n) || visited[i][j+1] || grid1[i][j+1] == 1) {
            compromiseTime = t + grid2[i][j+1];
            ans = max(ans, compromiseTime)
            pq.push({, i, j+1})
            visited[i][j+1] = true;
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid1[i][j] == 1 && visited[i][j]) {
                return -1;
            }
        }
    }
    return ans;
}


bool checkIndex(int i, int j, int m, int n) {
    if(i < 0 || j < 0 || i == m || j == n)
        return false;
    return true;
}

/*

You are given two `m x n` grids representing a network of servers: - `grid` where `0` = offline, `1` = healthy server, `2` = compromised server - `firewall` where each cell has a positive integer representing how many minutes of exposure it takes before that server gets compromised Every minute, a compromised server attacks all 4-directionally connected healthy servers. A healthy server gets compromised only after accumulating `firewall[r][c]` minutes of continuous exposure. Return the minimum number of minutes until all servers are compromised. If some servers can never be reached, return `-1`. 

**Example:** 
``` 
Grid: Firewall: 
2 1 1 
-1 5 1 1 1 2 1 1 Answer: 6 ```

**Constraints:** 
    - `1 <= m, n <= 300` 
    - `firewall[r][c]` is between `1` and `100`

2 1 1
1 1 1

0 1 4 
2 4 1

Ans: 6

Q2 Follow Up: If multiple servers can compromise together then in that case rate of compromisation will be proportial to no of servers compromised in adjacent

t = 0, left
t = 1, right


0, 0, 0
visited = true;

1, 0, 1
2, 1, 0

6, 0, 2
2, 1, 1

*/
