class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>res(matrix.size(), vector<int>(matrix[0].size()));

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                res[j][matrix.size() - i - 1] = matrix[i][j];
            }
        }

        matrix = res;
    }
};