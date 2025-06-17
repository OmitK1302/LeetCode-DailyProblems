class Solution {
public:
    int helper(string& s, string& p, int i ,int j) {
        if(i == s.length() && j == p.length()) return 1;

        if(j == p.length()) return 0;
        if(i == s.length()) {
            while(j < p.length()) {
                if(p[j++] != '*') return 0;
            }
            return 1;
        }

        if(s[i] == p[j] || p[j] == '?') {
            return helper(s, p, i+1, j+1);
        }

        if(p[j] == '*') {
            // char ch = s[i];
            // int curri = i;
            // while(s[curri] == ch) {
            //     curri++;
            // }

            // if(j == p.length() - 1 && curri >= s.length()) return 1;
            // curri--;
            // return helper(s, p, curri, j) || helper(s, p, i, j+1);

            return helper(s, p, i+1, j) || helper(s, p, i, j+1);

        }
        return 0;
        
    }
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0) == 1;
    }
};