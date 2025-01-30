class Solution {
public:
    bool helperDFS(vector<vector<int>>& graph, int currNode, int currColor, vector<int>& color){
        color[currNode] = currColor;
        for(int& i : graph[currNode]){
            if(color[i] == color[currNode]) return false;

            if(color[i] == -1){
                int colorOfI = 1 - currColor;
                if(helperDFS(graph, i, colorOfI, color) == false) return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);

        for(int i = 0; i < n; i++){
            if(color[i] == -1)
                if(helperDFS(graph, i, 1, color) == false) return false;
        }

        return true;
    }
};