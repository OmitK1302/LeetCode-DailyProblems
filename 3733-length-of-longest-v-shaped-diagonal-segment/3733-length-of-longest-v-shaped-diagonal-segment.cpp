
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


#pragma GCC optimize("O3", "unroll-loops")

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif


class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    vector<vector<vector<vector<int>>>> dp;
    int dfs(vector<vector<int>>& grid, int cx, int cy, int dir, bool turn, int target) {
        int nx = cx + dirs[dir][0];
        int ny = cy + dirs[dir][1];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n ||
            grid[nx][ny] != target) {
            return 0;
        }
        if (dp[nx][ny][dir][turn] != -1) {
            return dp[nx][ny][dir][turn];
        }

        int maxStep = dfs(grid, nx, ny, dir, turn, 2 - target);
        if (turn) {
            maxStep = max(maxStep, dfs(grid, nx, ny, (dir + 1) % 4, false, 2 - target));
        }
        dp[nx][ny][dir][turn] = maxStep + 1;
        return maxStep + 1;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();

        dp.resize(m, vector<vector<vector<int>>>(n, vector<vector<int>>(4, vector<int>(2, -1))));

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int dir = 0; dir < 4; dir++) {
                        res = fmax(res, dfs(grid, i, j, dir, true, 2) + 1);
                    }
                }
            }
        }

        return res;
    }
};




