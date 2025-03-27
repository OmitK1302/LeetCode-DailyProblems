class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // vector<vector<int>>res(matrix.size(), vector<int>(matrix[0].size()));

        // for(int i = 0; i < matrix.size() / 2; i++){
        //     int j = i;
        //     while(j < matrix[0].size() - i){
        //         for(int k = 0; k < 4; k++){

        //         }
        //     }
        // }

        for(int i = 0; i < matrix.size(); i++){
            for(int j = i+1; j < matrix[0].size(); j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
                // res[j][matrix.size() - i - 1] = matrix[i][j];
            }
        }
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size() / 2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix[0].size() - j - 1];
                matrix[i][matrix[0].size() - j - 1] = temp;
                // res[j][matrix.size() - i - 1] = matrix[i][j];
            }
        }


        // matrix = res;
    }
};