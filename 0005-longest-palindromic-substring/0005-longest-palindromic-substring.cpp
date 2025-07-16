class Solution {
public:
    bool solve(int i, int j, string& s) {
        if(i >= j) {
            return true;
        }

        if(s[i] == s[j]) {
            return solve(i + 1, j - 1, s);
        }

        return false;
    }

    string longestPalindrome(string s) {
        int maxLen = 1;
        int sp = 0;
        for(int i = 0; i < s.length(); i++) {
            for(int j = i + 1; j < s.length(); j++) {
                if(j - i + 1 > maxLen && solve(i, j, s)) {
                    maxLen = j - i + 1;
                    sp = i;
                }
            }
        }

        return s.substr(sp, maxLen);
    }
};