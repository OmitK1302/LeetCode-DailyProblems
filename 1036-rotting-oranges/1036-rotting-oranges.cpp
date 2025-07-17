class Solution {
public:
    int bfs(vector<vector<int>>& grid) {
        queue<pair<int, int>>que;
        int bad = 0;
        int total = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                int curr = grid[i][j];

                if(curr == 0) continue;

                if(grid[i][j] == 2) {
                    que.push({i, j});
                    bad++;
                }
                total++;
            }
        }

        if(total == 0) return 0;

        int good = total - bad;

        vector<vector<int>>dir = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1}
        };

        int res = 0;
        while(!que.empty()) {
            int n = que.size();
            res++;
            for(int i = 0; i < n; i++) {
                pair<int, int>curr = que.front();
                que.pop();
                int curri = curr.first;
                int currj = curr.second;
                for(int d = 0; d < 4; d++) {
                    int _i = curri + dir[d][0];
                    int _j = currj + dir[d][1];

                    if(_i >= 0 && _i < grid.size() && _j >= 0 && _j < grid[0].size() && grid[_i][_j] == 1) {
                        grid[_i][_j] = 2;
                        que.push({_i, _j});
                        good--;
                    }
                }
            }
        }

        return good == 0 ? res-1 : -1; 
    }

    int orangesRotting(vector<vector<int>>& grid) {
        // queue<pair<int, int>>que;
        
        

        return bfs(grid);
    }
};