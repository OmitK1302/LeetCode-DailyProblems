class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int low = 0, high = m-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int maxRow = 0;
            for(int i = 0; i < n; i++){
                if(mat[i][mid] > mat[maxRow][mid]){
                    maxRow = i;
                }
            }

            int left = mid - 1 >= 0 ? mat[maxRow][mid - 1] : -1;
            int right = mid + 1 < m ? mat[maxRow][mid + 1] : -1;
            
            if(mat[maxRow][mid] > left && mat[maxRow][mid] > right){
                return {maxRow, mid};
            }
            else if(mat[maxRow][mid]  < left){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return {-1, -1};



        // METHOD 1:
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         // bool curr = true;
        //         if(i - 1 != -1 && mat[i-1][j] > mat[i][j]) continue;
        //         if(i + 1 < n && mat[i+1][j] > mat[i][j]) continue;
        //         if(j - 1 != -1 && mat[i][j-1] > mat[i][j]) continue;
        //         if(j + 1 < m && mat[i][j+1] > mat[i][j]) continue;

        //         return {i, j};
        //     }
        // }

        // return {0, 0};
    }
};