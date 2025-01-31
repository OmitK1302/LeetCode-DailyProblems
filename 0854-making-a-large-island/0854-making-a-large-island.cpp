class Solution {
public:
   vector<pair<int, int>>dir = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };
    unordered_map<int, int>areaMap;
    void areaOfLand(vector<vector<int>>& grid, int i, int j, int currGroup) {
        int currLand = 0;
        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = -1;

        int m = grid.size();
        int n = grid[0].size();

        while (!que.empty()) {
            pair<int, int> currPos = que.front();
            que.pop();
            currLand++;

            for (pair<int, int> currDir : dir) {
                int _i = currPos.first + currDir.first;
                int _j = currPos.second + currDir.second;

                if (_i < m && _i >= 0 && _j < n && _j >= 0 && grid[_i][_j] == 1) {
                    que.push({_i, _j});
                    grid[_i][_j] = -1;
                }
            }
        }
        
        grid[i][j] = currGroup;
        que.push({i, j});
        while (!que.empty()) {
            pair<int, int> currPos = que.front();
            que.pop();

            for (pair<int, int> currDir : dir) {
                int _i = currPos.first + currDir.first;
                int _j = currPos.second + currDir.second;

                if (_i < m && _i >= 0 && _j < n && _j >= 0 && grid[_i][_j] == -1) {
                    que.push({_i, _j});
                    grid[_i][_j] = currGroup;
                }
            }
        }

        areaMap[currGroup] = currLand;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(m == 1 && grid[0][0]) return 1; 

        int res = 0;
        int group = 2;
        
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    areaOfLand(grid, i, j, group);
                    group++;
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                vector<bool>visited(areaMap.size() + 2, false);
                
                // explore above area
                // explore below aera
                // explore right area
                // explore left area
                // cout<<"for "<<i<<", "<<j<<" Directions:"<<endl;
                int currRes = 0;
                for (pair<int, int> currDir : dir) {
                    int _i = i + currDir.first;
                    int _j = j + currDir.second;
                    
                    // cout<<_i<<", "<<_j<<endl;
        
                    if (_i < m && _i >= 0 && _j < n && _j >= 0 && grid[_i][_j] > 1 ) {
                        currRes += (visited[grid[_i][_j]]) ? 0 : areaMap[grid[_i][_j]];
                        visited[grid[_i][_j]] = true;
                    }
                }
                
                res = max(res, currRes + 1);
            }
        }
        
        if(areaMap.size() == 1 && areaMap[2] == m*n) return res-1;

        return res;
        
    }
};