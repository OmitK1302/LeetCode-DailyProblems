class Solution {
public:

    int bitCnt(int val) {
        int res = 0;
        for(int i = 0; i < 32; i++) {
            if(((val >> i) & 1) == 1) {
                res++;
            }
        }

        return res;
    }
    vector<int> countBits(int n) {
        vector<int>res;
        for(int i = 0; i <= n; i++) {
            res.push_back(bitCnt(i));
        }
        return res;
    }
};