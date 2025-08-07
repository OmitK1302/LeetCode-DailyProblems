class Solution {
public:
    void bfs(vector<vector<int>>& grid, int srci, int srcj) {
        queue<pair<int, int>>que;
        que.push({srci, srcj});
        grid[srci][srcj] = 2;

        vector<vector<int>> dir = {
            {1,0}, {0,1}, {-1,0}, {0,-1}
        };

        while(!que.empty()) {
            pair<int, int> curr = que.front();
            que.pop();

            int i = curr.first;
            int j = curr.second;

            for(auto& it : dir) {
                int _i = i + it[0];
                int _j = j + it[1];

                if(_i >= 0 && _i < grid.size() && _j >= 0 && _j < grid[0].size() && grid[_i][_j] == 1) {
                    grid[_i][_j] = 2;
                    que.push({_i, _j});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            if(grid[i][0] == 1) {
                bfs(grid, i, 0);
            }
        }
        for(int i = 0; i < grid.size(); i++) {
            if(grid[i][grid[0].size() - 1] == 1) {
                bfs(grid, i, grid[0].size() - 1);
            }
        }
        for(int i = 0; i < grid[0].size(); i++) {
            if(grid[0][i] == 1) {
                bfs(grid, 0, i);
            }
        }
        for(int i = 0; i < grid[0].size(); i++) {
            if(grid[grid.size() - 1][i] == 1) {
                bfs(grid, grid.size() - 1, i);
            }
        }


        int cnt = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        // for(int i = 0; i < grid.size(); i++) {
        //     for(int j = 0; j < grid[0].size(); j++) {
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        

        return cnt;
    }
};