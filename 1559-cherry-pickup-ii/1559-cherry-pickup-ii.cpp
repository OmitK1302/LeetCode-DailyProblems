class Solution {
public:
    vector<vector<vector<int>>>dp;
    int helper(vector<vector<int>>& grid, int i1, int j1, int j2) {
        int m = grid.size();
        int n = grid[0].size();

        if(i1 >= m) {
            return 0;
        }

        if(j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) {
            return 0;
        }

        if(dp[i1][j1][j2] != -1) {
            return dp[i1][j1][j2];
        }

        int currVal = 0;
        if(j1 == j2) {
            currVal = grid[i1][j1];
        }
        else{
            currVal = grid[i1][j1] + grid[i1][j2];
        }

        int maxVal = 0;
        for(int k1 = -1; k1 <= 1; k1++) {
            for(int k2 = -1; k2 <= 1; k2++) {
                maxVal = max(maxVal, helper(grid, i1 + 1, j1 + k1, j2 + k2));
            }
        }

        dp[i1][j1][j2] = maxVal + currVal;
        return dp[i1][j1][j2];

        // int ll = helper(grid, i1 + 1, j1 - 1; i2 + 1; j2 - 1);
        // int lm = helper(grid, i1 + 1, j1 - 1; i2 + 1; j2);
        // int lr = helper(grid, i1 + 1, j1 - 1; i2 + 1; j2 + 1);
        // int ml = helper(grid, i1 + 1, j1; i2 + 1; j2 - 1);
        // int mm = helper(grid, i1 + 1, j1; i2 + 1; j2);
        // int mr = helper(grid, i1 + 1, j1; i2 + 1; j2 - 1);
        // int rl = helper(grid, i1 + 1, j1 + 1; i2 + 1; j2 - 1);
        // int rm = helper(grid, i1 + 1, j1 + 1; i2 + 1; j2);
        // int rr = helper(grid, i1 + 1, j1 + 1; i2 + 1; j2 + 1);
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.resize(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return helper(grid, 0, 0, n-1);
    }
};