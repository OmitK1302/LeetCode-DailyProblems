class Solution {
public:
    long long flowerGame(int n, int m) {
        long long temp1 = n;
        long long temp2 = m;

        return (temp1 / 2) * (temp2 - (temp2 / 2)) + ((temp2 / 2) * (temp1 - (temp1 / 2)));
    }
};