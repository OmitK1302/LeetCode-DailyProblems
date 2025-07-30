class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0;
        for (int num : nums) {
            maxVal = max(maxVal, num);
        }

        int res = 0;
        int count = 0;
        for (int num : nums) {
            if (num == maxVal) {
                count++;
                res = max(res, count);
            } else {
                count = 0;
            }
        }

        return res;
    }

};