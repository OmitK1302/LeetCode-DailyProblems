class Solution {
public:
    int helper1(vector<vector<int>>& fruits, int i, int j, vector<vector<int>>& dp) {
        if(i == fruits.size() - 1 && j == fruits.size() - 1) return fruits[i][j];
        if(i >= j || j < 0 || j >= fruits.size()) return INT_MIN;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] =  max(helper1(fruits, i + 1, j - 1, dp), max(helper1(fruits, i + 1, j, dp), helper1(fruits, i + 1, j + 1, dp))) + fruits[i][j];
    
    }

    int helper2(vector<vector<int>>& fruits, int i, int j, vector<vector<int>>& dp) {
        if(i == fruits.size() - 1 && j == fruits.size() - 1) return fruits[i][j];
        if(j >= i || i < 0 || i >= fruits.size()) return INT_MIN;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] =  max(helper2(fruits, i - 1, j + 1, dp), max(helper2(fruits, i, j+1, dp), helper2(fruits, i + 1, j + 1, dp))) + fruits[i][j];
    
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        // diagonal valeues
        int res = 0;
        for(int i = 0; i < fruits.size(); i++) {
            res += fruits[i][i];
        }
        
        int n = fruits.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));

        // left bottom
        res += helper1(fruits, 0, n-1, dp);

        // right top
        res += helper2(fruits, n-1, 0, dp);

        return res - 2*(fruits[n-1][n-1]);
    }
};