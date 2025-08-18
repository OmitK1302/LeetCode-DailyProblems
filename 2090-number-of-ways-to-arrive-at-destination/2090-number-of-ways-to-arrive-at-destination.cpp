// class Solution {
// public:
//     int dijkstra(vector<vector<pair<int, int>>>& adj, int n, int src) {
//         vector<int>res(n, INT_MAX);
//         res[src] = 0;

//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         pq.push({0, src});

//         while(!pq.empty()) {
//             pair<int, int>curr = pq.top();
//             pq.pop();

//             int currNode = curr.second;
//             int currCst = curr.first;

//             for(auto& node : adj[currNode]) {
//                 if(node.second + currCst < res[node.first]) {
//                     res[node.first] = node.second + currCst;
//                     pq.push({node.second + currCst, node.first});
//                 }
//             }
//         }

//         return res[n-1];
//     }


//     int dfs(vector<vector<pair<int, int>>>& adj, int curr, int currCst) {
//         for(auto& it : )
//     }

//     int countPaths(int n, vector<vector<int>>& roads) {
//         vector<vector<pair<int, int>>> adj(n);
//         for(auto& it : roads) {
//             adj[it[0]].push_back({it[1], it[2]});
//             adj[it[1]].push_back({it[0], it[2]});
//         }

//         int dist = dijkstra(adj, n, 0);

//         // return ways(adj, n, 0, dist);
//         return dist;
//     }
// };

class Solution {
public:
    const int MOD = 1e9 + 7;
    const long long INF = (1LL << 62);
    vector<long long> dist;
    vector<int> dp; 

    long long dijkstra(vector<vector<pair<int, long long>>>& adj, int n, int src) {
        dist.assign(n, INF);
        dist[src] = 0;

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;
        pq.push({0LL, src});

        while(!pq.empty()) {
            auto [currCst, currNode] = pq.top();
            pq.pop();

            if (currCst != dist[currNode]) continue; 

            for (auto& node : adj[currNode]) {
                int v = node.first;
                long long w = node.second;
                if (currCst + w < dist[v]) {
                    dist[v] = currCst + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[n-1];
    }

    int dfs(vector<vector<pair<int, long long>>>& adj, int curr, int n) {
        if (curr == n-1) return 1;
        if (dp[curr] != -1) return dp[curr];

        long long ways = 0;
        for (auto& it : adj[curr]) {
            int next = it.first;
            long long cost = it.second;
            if (dist[curr] + cost == dist[next]) {
                ways += dfs(adj, next, n);
                if (ways >= MOD) ways -= MOD;
            }
        }
        return dp[curr] = (int)(ways % MOD);
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> adj(n);
        for (auto& e : roads) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, (long long)w});
            adj[v].push_back({u, (long long)w});
        }

        long long shortest = dijkstra(adj, n, 0);
        // (void)shortest;

        dp.assign(n, -1);
        return dfs(adj, 0, n);
    }
};
