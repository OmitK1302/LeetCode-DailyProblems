class Solution {
public:
    int numSub(string s) {
        int MOD = 1e9 + 7;
        long long curr = 0;
        long long res = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                curr++;
                res = (res + curr) % MOD;
            }
            else {
                curr = 0;
            }
        }

        return res % MOD;
    }
};