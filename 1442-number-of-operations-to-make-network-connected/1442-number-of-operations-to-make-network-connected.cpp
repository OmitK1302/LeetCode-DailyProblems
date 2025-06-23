class Solution {
public:
    // void bfs(int i, vector<vector<int>>& adj, vector<bool>& visited) {
    //     visited[i] = true;
    //     queue<int>que;
    //     que.push(i);

    //     while(!que.empty()) {
    //         int curr = que.front();
    //         que.pop();
    //         visited[curr] = true;
    //         for(int& node : adj[curr]) {
    //             if(!visited[node]) {
    //                 que.push(node);
    //             }
    //         }
    //     }
    // }
    // int makeConnected(int n, vector<vector<int>>& connections) {
        // int edges = connections.size();
        // if(n > edges + 1) return -1;

    //     vector<vector<int>>adj(n-1);
    //     for(vector<int>& con : connections) {
    //         adj[con[0]].push_back(con[1]);
    //         adj[con[1]].push_back(con[0]);
    //     }

    //     vector<bool>visited(n, 0);
    //     int count = 0;
    //     for(int i = 0; i < n; i++) {
    //         if(!visited[i]) {
    //             bfs(i, adj, visited);
    //             count++;
    //         }
    //     }

    //     return count-1;
    // }

    int find(int i, vector<int>& leaders) {
        if(i == leaders[i]) return i;

        return leaders[i] = find(leaders[i], leaders);
    }

    bool Union(int i, int j, vector<int>& leaders, vector<int>&rank) {
        int i_lead = find(i, leaders);
        int j_lead = find(j, leaders);

        if(i_lead == j_lead) return false;

        if(rank[i_lead] == rank[j_lead]) {
            leaders[i_lead] = j_lead;
            rank[j_lead]++;
        }

        else if(rank[i_lead] < rank[j_lead]) {
            leaders[i_lead] = j_lead;
        }
        else {
            leaders[j_lead] = i_lead;
        }

        return true;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int e = connections.size();
        if(n > e + 1) return -1;

        vector<int>rank(n, 0);
        vector<int>leaders(n);
        for(int i = 0; i < n; i++) {
            leaders[i] = i;
        }

        int vert = 1;
        int edge = 0;
        for(auto& it : connections) {
            if(Union(it[0], it[1], leaders, rank)) {
                edge++;
                vert++;
            }
        }

        return n - vert;
    }
};