class Solution {
public:
    int findClosest(int x, int y, int z) {
        return abs(z-x) > abs(z-y) ? 2 : abs(z-x) == abs(z-y) ? 0 : 1;
    }
};