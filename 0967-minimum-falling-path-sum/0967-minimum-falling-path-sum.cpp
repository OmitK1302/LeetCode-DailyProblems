class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = m-2; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                int left = (j - 1 < 0) ? INT_MAX - 500 : matrix[i][j] + matrix[i+1][j-1];
                int right = (j + 1 >= n) ? INT_MAX - 500 : matrix[i][j] + matrix[i+1][j+1];
                int down = matrix[i][j] + matrix[i+1][j];

                matrix[i][j] = min(left, min(right, down));
            }
        }

        int res = INT_MAX;
        for(int j = 0; j < n; j++) {
            res = min(res, matrix[0][j]);
        }

        return res;
    }
};