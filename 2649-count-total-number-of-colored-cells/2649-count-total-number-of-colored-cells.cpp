class Solution {
public:
    long long coloredCells(int n) {
        long long res = 1;
        int k = 1;
        for(int i = 1; i < n; i++){
            res += (k*4);
            k++;
        }

        return res;
    }
};