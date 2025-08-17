class Solution {
public:
    int helper(int minVal, int maxVal, vector<vector<int>>& dp) {
        if(minVal == maxVal-1) return 1;

        if(dp[minVal][maxVal] != -1) return dp[minVal][maxVal];

        int res = 0;
        for(int i = minVal+1; i < maxVal; i++) {
            int ls = helper(minVal, i, dp);
            int rs = helper(i, maxVal, dp);

            res += (ls * rs);
        }

        return dp[minVal][maxVal] = res;
    }
    int numTrees(int n) {
        vector<vector<int>>dp(n+2, vector<int>(n+2, -1));
        return helper(0,n+1, dp);
    }
};