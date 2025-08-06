class Solution {
public:
    void bfs(vector<vector<int>>& adj, int src, vector<bool>& visited) {
        if(visited[src]) return;

        queue<int>que;
        que.push(src);

        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            for(auto& node : adj[curr]) {
                if(!visited[node]) {
                    visited[node] = true;
                    que.push(node);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n+1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        int cnt = 0;
        vector<bool>visited(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                cnt++;
                bfs(adj, i, visited);
            }
        }

        return cnt;
    }
};