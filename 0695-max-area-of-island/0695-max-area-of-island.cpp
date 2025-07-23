class Solution {
public:
    vector<vector<int>>dir = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };
    int area(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = -1;
        int res = 1;
        int m = grid.size();
        int n = grid[0].size();
        for(auto& it: dir) {
            int _i = i + it[0];
            int _j = j + it[1];

            if(_j >= 0 && _j < n && _i >= 0 && _i < m && grid[_i][_j] == 1) {
                res += (area(grid, _i, _j));
            }
        }

        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    res = max(res, area(grid, i, j));
                }
            }
        }

        return res;
    }
};