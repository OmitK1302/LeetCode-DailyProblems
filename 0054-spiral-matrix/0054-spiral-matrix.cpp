class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int>res;

        if(row == 1 && col == 1) return {matrix[0][0]};
        if(row == 1) return matrix[0];

        for(int i = 0; i < (min(row, col) + 1) / 2; i++) {
            for(int j = i; j < col - i; j++) {
                res.push_back(matrix[i][j]);
            }
            for(int j = i+1; j < row - i; j++) {
                res.push_back(matrix[j][col - i - 1]);
            }

            if (row - i - 1 != i) {
                for(int j = col - i - 2; j >= i; j--) {
                    res.push_back(matrix[row - i - 1][j]);
                }
            }

            if (col - i - 1 != i) {
                for(int j = row - i - 2; j > i; j--) {
                    res.push_back(matrix[j][i]);
                }
            }
        }
        return res;
    }
};