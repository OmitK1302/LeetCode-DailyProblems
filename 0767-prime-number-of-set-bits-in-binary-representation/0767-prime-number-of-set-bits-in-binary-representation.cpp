class Solution {
public:
    bool isPrime(int val) {
        if(val <= 1) return false;
        for(int i = 2; i < val; i++) {
            if(val % i == 0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for(int i = left; i <= right; i++) {
            int bits = __builtin_popcount(i);

            if(isPrime(bits)){
                res++;
                cout<<bits<<" ";
            }
        }

        return res;
    }
};