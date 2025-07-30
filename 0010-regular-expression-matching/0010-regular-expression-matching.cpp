class Solution {
public:
    vector<vector<int>>dp;
    int helper(string s, string p, int i, int j) {

        if(i == s.length() && j == p.length()) {
            return 1;
        }
        if(i > s.length() || j > p.length()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(j + 1 < p.length() && p[j + 1] == '*') {
            if(p[j] == s[i] || p[j] == '.') {
                return dp[i][j] = (i < s.length() ? helper(s, p, i+1, j) : 0) | helper(s, p, i, j+2);
            }
            else{
                return dp[i][j] = helper(s, p, i, j+2);
            }
        }
        else if(p[j] == '.' || p[j] == s[i]) {
            return dp[i][j] = helper(s, p, i+1, j+1);
        }

        return dp[i][j] = 0;
    }

    bool isMatch(string s, string p) {
        char pre = p[0];
        int n = s.length();
        int m = p.length();
        dp.resize(n+1, vector<int>(m+1, -1));
        return helper(s, p, 0, 0) == 1;
    }
};