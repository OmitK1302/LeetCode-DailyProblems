class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>indeg(n);

        // calculate the indegree
        for(int i = 0; i < n; i++) {
            for(int& node : adj[i]) {
                indeg[node]++;
            }
        }

        // push the nodes with indegree 0 into the queue
        queue<int>que;
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) {
                que.push(i);
            }
        }

        // perform bfs
        vector<int>res;
        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            res.push_back(curr);

            for(int& neigh : adj[curr]) {
                indeg[neigh]--;
                if(indeg[neigh] == 0) {
                    que.push(neigh);
                }
            }
        }

        // Cycle Detection
        if(n != res.size()) {
            return {};
        }
        return res;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);
        for(vector<int>& preq : prerequisites) {
            adj[preq[1]]. push_back(preq[0]);
        }

        return topoSort(adj);
        
    }
};