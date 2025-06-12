class Solution {
public:
    int helper(vector<int>& nums, int target, int i, int currSum) {
        if(i == nums.size()) {
            if(currSum == target) {
                return 1;
            }
            return 0;
        }

        int add = helper(nums, target, i + 1, currSum + nums[i]);
        int sub = helper(nums, target, i + 1, currSum - nums[i]);

        return add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, target, 0, 0);
    }
};