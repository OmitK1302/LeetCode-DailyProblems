class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // bool curr = true;
                if(i - 1 != -1 && mat[i-1][j] > mat[i][j]) continue;
                if(i + 1 < n && mat[i+1][j] > mat[i][j]) continue;
                if(j - 1 != -1 && mat[i][j-1] > mat[i][j]) continue;
                if(j + 1 < m && mat[i][j+1] > mat[i][j]) continue;

                return {i, j};
            }
        }

        return {0, 0};
    }
};