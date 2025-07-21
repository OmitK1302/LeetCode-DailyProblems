class Solution {
public:
    string makeFancyString(string s) {
        string res;
        res += s[0];
        int cnt = 1;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i-1]) {
                if(cnt < 2) {
                    cnt++;
                    res += s[i];
                }
                else{
                    continue;
                }
            }
            else{
                cnt = 1;
                res += s[i];
            }
        }

        return res;
    }
};