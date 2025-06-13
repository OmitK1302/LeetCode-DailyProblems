class Solution {
public:
    // int helper(string s, int i, int j) {
    //     if(i >= j) {
    //         return 0;
    //     }
    //     if(s[i] == s[j]) {
    //         return helper(s, i + 1, j - 1);
    //     }

    //     return max(helper(s, i+1, j), helper(s, i, j+1)) + 1;

    // }
    int minInsertions(string s) {
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());

        int l1 = s1.length();
        int l2 = s2.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

        
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return s.length() - dp[l1][l2];
    }
};