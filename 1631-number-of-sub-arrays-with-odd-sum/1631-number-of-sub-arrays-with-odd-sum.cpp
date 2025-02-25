class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int oddCount = 0, evenCount = 1; 
        int sum = 0, res = 0;
        const int MOD = 1e9 + 7;

        for (int num : arr) {
            sum += num;
            if (sum % 2 == 0) {
                res = (res + oddCount) % MOD;
                evenCount++;
            } else {
                res = (res + evenCount) % MOD;
                oddCount++;
            }
        }

        return res;
    }
};
