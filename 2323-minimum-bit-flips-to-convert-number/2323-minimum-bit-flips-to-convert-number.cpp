class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = goal ^ start;
        // return n;
        int res = 0;
        while(n != 0){
            if(n & 1 != 0) res++;
            n = n >> 1;
        }

        return res;
    }
};