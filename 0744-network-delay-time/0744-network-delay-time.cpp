class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        vector<vector<pair<int, int>>>adj(n+1);
        for(auto& it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int>res(n+1, INT_MAX);
        res[k] = 0;
        while(!pq.empty()) {
            pair<int, int>curr = pq.top();
            pq.pop();

            int currWt = curr.first;
            int currNode = curr.second;

            for(auto& it : adj[currNode]) {
                // cout<<it.first<<" "<<it.second<<", ";
                if(currWt + it.second < res[it.first]) {
                    pq.push({currWt + it.second, it.first});
                    res[it.first] = currWt + it.second;
                }
            }
        }

        int result = 0;
        // for(int i = 1; i <= n; i++) {
        //     int it  = res[i];
        //     if(it == INT_MAX) return -1;
        //     result += it; 
        // }

        for(int i = 1; i <= n; i++) {
            int it = res[i];
            if(it == INT_MAX) return -1;
            result = max(result, it);
        }

        return result;
    }
};