
// ------------------------------------------------ MEMOIZATION (CAUSES TLE) ------------------------------------------------

// class Solution {
// public:
    // br, bl, tl, tr
    // vector<pair<int,int>> dirs = {{1,1},{1,-1},{-1,-1},{-1,1}};
    
    // int helper(vector<vector<int>>& grid, int i, int j, bool turned, int dir, int val, vector<vector<vector<vector<vector<int>>>>>& dp) {
    //     if(dp[i][j][dir][turned][val] != -1) return dp[i][j][dir][turned][val];

    //     int n = grid.size(), m = grid[0].size();
        
    //     val = (val == 2) ? 0 : 2;
        
    //     int res = 1;
    //     int ni = i + dirs[dir].first;
    //     int nj = j + dirs[dir].second;
        
    //     if(ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == val) {
    //         res = max(res, 1 + helper(grid, ni, nj, turned, dir, val, dp));
    //     }
        
    //     if(!turned) {
    //         int newDir = (dir + 1) % 4;
    //         int ti = i + dirs[newDir].first;
    //         int tj = j + dirs[newDir].second;
    //         if(ti >= 0 && tj >= 0 && ti < n && tj < m && grid[ti][tj] == val) {
    //             res = max(res, 1 + helper(grid, ti, tj, true, newDir, val, dp));
    //         }
    //     }
        
    //     return dp[i][j][dir][turned][val] = res;
    // }

    // int lenOfVDiagonal(vector<vector<int>>& grid) {
    //     int n = grid.size(), m = grid[0].size();
        
    //     // DP dimensions: [n][m][4 directions][2 turned][3 possible vals]
    //     vector<vector<vector<vector<vector<int>>>>> dp(n, vector<vector<vector<vector<int>>>>(m, vector<vector<vector<int>>>(4, vector<vector<int>>(2, vector<int>(3, -1)))));
        
    //     int ans = 0;
    //     for(int i = 0; i < n; i++) {
    //         for(int j = 0; j < m; j++) {
    //             if(grid[i][j] == 1) {
    //                 for(int d = 0; d < 4; d++) {
    //                     ans = max(ans, helper(grid, i, j, false, d, 1, dp));
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }

// ------------------------------------------------------------------------------------------------------------------------------------------------

// };



class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

        vector<vector<vector<vector<int>>>> dp(m, vector<vector<vector<int>>>(n, vector<vector<int>>(4, vector<int>(2, -1))));
        // int memo[m][n][4][2];
        // memset(memo, -1, sizeof(memo));

        function<int(int, int, int, bool, int)> dfs =
            [&](int cx, int cy, int direction, bool turn, int target) -> int {
            int nx = cx + dirs[direction][0];
            int ny = cy + dirs[direction][1];
            /* If it goes beyond the boundary or the next node's value is not
             * the target value, then return */
            if (nx < 0 || ny < 0 || nx >= m || ny >= n ||
                grid[nx][ny] != target) {
                return 0;
            }
            if (dp[nx][ny][direction][turn] != -1) {
                return dp[nx][ny][direction][turn];
            }

            /* Continue walking in the original direction. */
            int maxStep = dfs(nx, ny, direction, turn, 2 - target);
            if (turn) {
                /* Clockwise rotate 90 degrees turn */
                maxStep = fmax(maxStep, dfs(nx, ny, (direction + 1) % 4, false,
                                            2 - target));
            }
            dp[nx][ny][direction][turn] = maxStep + 1;
            return maxStep + 1;
        };

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int direction = 0; direction < 4; ++direction) {
                        res = fmax(res, dfs(i, j, direction, true, 2) + 1);
                    }
                }
            }
        }

        return res;
    }
};
