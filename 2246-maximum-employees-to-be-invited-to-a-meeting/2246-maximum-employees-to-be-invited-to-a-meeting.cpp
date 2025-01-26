class Solution {
public:

    int BFS(int start, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        int maxDist = 0;
        queue<pair<int, int>>que;
        que.push({start, 0});

        while(!que.empty()){
            auto[currNode, currLength] = que.front();
            que.pop();

            for(auto& ngbr : adj[currNode]) {
                if(!visited[ngbr]){
                    visited[ngbr] = true;
                    maxDist = max(currLength + 1, maxDist);
                    que.push({ngbr, currLength + 1});
                }
            }
        }

        return maxDist;
    }

    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int, vector<int>>adj;

        for(int i = 0; i < n; i++){
            int u = i;
            int v = favorite[i];
            adj[v].push_back(u);
        }

        int maxCycleLength = 0;
        int cycleLength2 = 0;

        vector<bool>visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                unordered_map<int, int>mp;
                int currNode = i;
                int currNodeCnt = 0;

                while(!visited[currNode]){
                    visited[currNode] = true;
                    mp[currNode] = currNodeCnt;

                    currNodeCnt += 1;
                    int nextNode = favorite[currNode];

                    if(mp.count(nextNode)){ // cycle detected
                        int cycleLength = currNodeCnt - mp[nextNode];
                        maxCycleLength = max(maxCycleLength, cycleLength);

                        if(cycleLength == 2){
                            vector<bool>visitedNodes(n, false);
                            visitedNodes[currNode] = true;
                            visitedNodes[nextNode] = true;
                            cycleLength2 += 2 + (BFS(currNode, adj, visitedNodes) + BFS(nextNode, adj, visitedNodes));
                        }

                        break;
                    }

                    currNode = nextNode;
                }
            }
        }

        return max(maxCycleLength, cycleLength2);
    }
};