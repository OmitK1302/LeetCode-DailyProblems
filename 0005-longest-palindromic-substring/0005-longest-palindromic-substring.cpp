class Solution {
public:
    vector<vector<int>>dp;
    bool solve(int i, int j, string& s) {
        if(i >= j) {
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) {
            bool curr = solve(i + 1, j - 1, s);
            dp[i][j] = curr ? 1 : 0;
            return curr;
        }
        dp[i][j] = 0;
        return false;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        dp.resize(n, vector<int>(n, -1));

        int maxLen = 1;
        int sp = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(j - i + 1 > maxLen && solve(i, j, s)) {
                    maxLen = j - i + 1;
                    sp = i;
                }
            }
        }

        return s.substr(sp, maxLen);
    }
};