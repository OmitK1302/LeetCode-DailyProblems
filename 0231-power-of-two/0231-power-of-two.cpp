class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long temp = n;
        return temp != 0 && ((temp & (temp-1)) == 0);
    }
};