class Solution {
public:
    int diagonalSum(vector<vector<int>>& matrix) {
        // Code here
        int sum1 = 0;
        // int sum2;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(i == j){
                    sum1 +=  matrix[i][j];
                }
            }
        }
        // cout<<sum1<<" ";
        
        
        int sum2 = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(j == matrix[i].size() - 1){
                    if(i == j-i) continue;
                    sum2 += matrix[i][j-i];
                }
                
            }
        }
        // cout<<sum2<<" ";
        
        int result = sum1+ sum2;
        int n = matrix.size();
        return result;
    }
};