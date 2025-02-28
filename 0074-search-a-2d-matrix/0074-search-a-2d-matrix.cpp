class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0;
        int right = (m*n) - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            int r1 = mid / m, c1 = mid % m;

            if(matrix[r1][c1] == target){
                return true;
            }
            else if(matrix[r1][c1] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return false;



        // for(int i = 0; i < matrix.size(); i++){
        //     for(int j = 0; j < matrix[0].size(); j++){
        //         if(matrix[i][j] == target) return true;
        //     }
        // }

        // int start = 0, end = 0;
        // while(start < end){
        //     if(matrix[start][0] < target){

        //     }
        // }
        // int row = -1;
        // int i = 0;

        // int top = 0;
        // int bottom = matrix.size() - 1;
        // while(top < bottom){
        //     int mid = (top + bottom) / 2;
        //     if(matrix[0][mid] > target){
        //         bottom = mid - 1;
        //     }
        //     else if(matrix[0][mid] <= target){

        //     }
        // }



        // for(int i = 0; i < matrix.size(); i++){
        //     if(matrix[i][0] > target){
        //         row = i - 1;
        //         break;
        //     }
        //     if(matrix[i][0] == target) return true; 
        // }

        // if(row == -1) row = matrix.size() - 1;

        // for(int j = 0; j < matrix[0].size(); j++){
        //     if(matrix[row][j] == target) return true;
        // }

        return false;
    }
};