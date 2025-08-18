class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int n, int dist, int src) {
        vector<int>res(n, INT_MAX);
        res[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while(!pq.empty()) {
            pair<int, int>curr = pq.top();
            pq.pop();

            int currNode = curr.second;
            int currCst = curr.first;

            for(auto& node : adj[currNode]) {
                if(node.second + currCst < res[node.first]) {
                    res[node.first] = node.second + currCst;
                    pq.push({node.second + currCst, node.first});
                }
            }
        }

        vector<int>nodes;
        for(int i = 0; i < n; i++) {
            if(res[i] <= dist && i != src) {
                nodes.push_back(i);
            }
        }

        return nodes;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        int minSize = n;
        int res = 0;
        for(int i = 0; i < n; i++) {
            vector<int>temp = dijkstra(adj, n, distanceThreshold, i);
            if(temp.size() <= minSize) {
                minSize = temp.size();
                res = i;
            }
        }

        // for(auto& i : temp) {
        //     cout<<i<<" ";
        // }

        return res;
    }
};