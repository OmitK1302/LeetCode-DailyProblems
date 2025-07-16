class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        long long res = 0;
        for(int i = 0; i < arr.size(); i++) {
            int leftMin = -1;
            int rightMin = n;

            for(int j = i-1; j >= 0; j--) {
                if(arr[j] < arr[i]) {
                    leftMin = j;
                    break;
                }
            }

            for(int j = i+1; j < n; j++) {
                if(arr[j] <= arr[i]) {
                    rightMin = j;
                    break;
                }
            }

            long long left = i - leftMin;
            long long right = rightMin - i;

            res = (res + (1LL * arr[i] * left % MOD * right % MOD)) % MOD;

            // res += ((((arr[i] * (left) % MOD) * (rightMin - i)) % MOD) % MOD);
        }

        return res;
    }
};