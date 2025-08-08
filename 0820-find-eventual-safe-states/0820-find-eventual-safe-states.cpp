class Solution {
public:
    // bool containsCycle(vector<vector<int>>& graph, int src, vector<bool>&visited) {
    //     // visited[src] = true;
    //     // bool curr = true;
    //     for(int& nodes : graph[src]) {
    //         if(visited[nodes]) return true;
    //         visited[nodes] = true;
    //         bool curr = containsCycle(graph, nodes, visited);
    //         if(curr == true) return true; 
    //         visited[nodes] = false;
    //     }
    //     return false;
    // }
    // vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    //     vector<bool>visited(graph.size(), false);
    //     vector<bool>visitedTemp = visited;
    //     vector<int>res;
    //     for(int i = 0; i < graph.size(); i++) {
    //         visitedTemp[i] = true;
    //         if(!containsCycle(graph, i, visitedTemp)) {
    //             res.push_back(i);
    //         }
    //         visitedTemp = visited;
    //     }
        

    //     return res;
    // }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        queue<int>que;
        int n = graph.size();
        vector<vector<int>>adj(n);
        vector<int>inDeg(n, 0);
        for(int i = 0; i < graph.size(); i++) {
            for(int& node : graph[i]) {
                adj[node].push_back(i);
                inDeg[i]++;
            }   
        }


        // for(int i = 0; i < n; i++) {
        //     // inDeg[graph[i]]++
        //     for(int& val : graph[i]) {
        //         inDeg[val]++;
        //     }
        // }


        for(int i = 0; i < inDeg.size(); i++) {
            if(inDeg[i] == 0) {
                que.push(i);
            }
        }

        vector<bool>safe(n);
        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            safe[curr] = true;

            for(int& node : adj[curr]) {
                if(--inDeg[node] == 0) que.push(node);
            }
        }

        vector<int>res;
        for(int i = 0; i < inDeg.size(); i++) {
            if(safe[i]) res.push_back(i);
        }
        return res;
    }
};