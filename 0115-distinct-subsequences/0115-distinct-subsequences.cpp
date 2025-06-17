class Solution {
public:
    // int cnt = 0;
    // string sTemp;
    // string tTemp;
    // vector<int>dp;
    // int helper(string currstr, int curr) {
    //     if(curr == sTemp.length()) {
    //         if(currstr == tTemp) {
    //             return 1;
    //         }
    //         return 0;
    //     }

    //     if(dp[curr] != -1) {
    //         return dp[curr];
    //     }
    //     string temp = currstr + sTemp[curr];

    //     return dp[curr] = helper(temp, curr + 1) + helper(currstr, curr + 1);
    // }

    int helper(string &s, int i, string &t, int j, vector<vector<int>>& dp) {
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(s[i] == t[j]) {
            ans = helper(s, i-1, t, j-1, dp) + helper(s, i-1, t, j, dp);
        }
        else{
            ans = helper(s, i-1, t, j, dp);
        }

        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        // sTemp = s;
        // tTemp = t;
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // dp.resize(n + 1, -1);
        return helper(s, n-1, t, m-1, dp);
        // return cnt;
    }
};