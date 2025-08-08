class Solution {
public:
    bool helperBfs(vector<vector<int>>& graph, vector<int>& color, int src) {
        int clr = 0;
        
        queue<int>que;
        que.push(src);

        while(!que.empty()) {
            clr = clr == 0 ? 1 : 0;
            int n = que.size();
            for(int i = 0; i < n; i++) {
                int curr = que.front();
                que.pop();

                for(auto& node : graph[curr]) {
                    if(color[node] != -1) {
                        if(color[node] != clr) return false;
                    }
                    else{
                        color[node] = clr;
                        que.push(node);
                    }
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++) {
            if(color[i] == -1) {
                if(!helperBfs(graph, color, i)) return false;
            }
        }
        return true;
    }
};