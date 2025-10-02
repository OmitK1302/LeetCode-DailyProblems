class Solution {
    vector<vector<int>>dp;
public:
    int helper(vector<vector<int>>& matrix, int i, int j, int prevEl) {
        if(i == matrix.size() || i < 0 || j < 0 || j == matrix[0].size() || matrix[i][j] <= prevEl) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        // int left = INT_MIN;
        // int right = INT_MIN;
        // int down = INT_MIN;
        // int up = INT_MIN;

        return dp[i][j] = max(helper(matrix, i, j-1, matrix[i][j]), max(helper(matrix, i, j+1, matrix[i][j]), max(helper(matrix, i-1, j, matrix[i][j]), helper(matrix, i+1, j, matrix[i][j])))) + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        int row = matrix.size();
        int col = matrix[0].size();

        dp.resize(row, vector<int>(col, -1));

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                res = max(res, helper(matrix, i, j, -1));
            }
        }
        return res;
    }
};