class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return -1;

        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        vector<bool> inc(n, false);
        inc[0] = true;
        for (int i = 1; i < n; i++) {
            if (inc[i-1] && nums[i-1] < nums[i])
                inc[i] = true;
            else
                inc[i] = false;
        }

        vector<bool> dec(n, false);
        dec[n-1] = true;
        for (int i = n-2; i >= 0; i--) {
            if (dec[i+1] && nums[i] > nums[i+1])
                dec[i] = true;
            else
                dec[i] = false;
        }

        long long ans = LLONG_MAX;
        for (int i = 1; i < n; i++) {
            if (inc[i-1] && dec[i]) {
                long long leftSum = prefix[i-1];
                long long rightSum = prefix[n-1] - prefix[i-1];
                ans = min(ans, llabs(leftSum - rightSum));
            }
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};
