
// -----------------------------------MEMOISATION-----------------------------------------------------------------
// class Solution {
// public:
//     vector<vector<int>>dp;
//     int findMinPath(vector<vector<int>>& triangle, int row, int currIn){
//         if(row == triangle.size()){
//             return 0;
//         }
//         if(dp[row][currIn] != -1){
//             return dp[row][currIn];
//         }
//         int sameIndex = triangle[row][currIn] + findMinPath(triangle, row + 1, currIn);
//         int altIndex = triangle[row][currIn] + findMinPath(triangle, row + 1, currIn + 1);

//         dp[row][currIn] = min(sameIndex, altIndex);
//         return dp[row][currIn];
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         dp.resize(triangle.size(), vector<int>(triangle.size(), -1));
//         return findMinPath(triangle, 0, 0);
//     }
// };


// -------------------------------------------TABULATION---------------------------------------------------------

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int>dp = triangle[m-1];

        for(int i = m-2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                dp[j] = min(dp[j+1], dp[j]) + triangle[i][j];
            }
        }

        return dp[0];
    }
};