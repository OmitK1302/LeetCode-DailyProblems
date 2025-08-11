class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int>inDeg(numCourses, 0);
        int cnt = 0;
        for(auto& it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            inDeg[it[0]]++;
        }


        queue<int>que;
        for(int i = 0; i < inDeg.size(); i++) {
            if(inDeg[i] == 0) {
                que.push(i);
            }
        }

        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            cnt++;

            for(int& node : adj[curr]) {
                inDeg[node]--;
                if(inDeg[node] == 0) {
                    que.push(node);
                }
            }
        }

        return cnt == numCourses;
    }
};