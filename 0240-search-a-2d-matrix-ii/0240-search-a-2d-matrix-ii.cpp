class Solution {
public:
    bool binarySearch(vector<vector<int>>& arr, int i, int target){
        int left = 0;
        int right = arr[0].size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(arr[i][mid] == target){
                return true;
            }
            else if(arr[i][mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][0] > target) return false;
            if(binarySearch(matrix, i, target)) return true;
        }

        return false;
    }
};