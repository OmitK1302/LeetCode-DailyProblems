class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int res = 0;
        int n = nums.size();
        int finalVal = nums[n/2];

        for(int& num : nums) {
            res += abs(num - finalVal);
        }

        return res;
    }
};