class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<int>& nums, int target, int i, int currSum, int offset) {
        if(i == nums.size()) {
            if(currSum == target) {
                return 1;
            }
            return 0;
        }

        if(dp[i][currSum + offset] != -1) return dp[i][currSum + offset];

        int add = helper(nums, target, i + 1, currSum + nums[i], offset);
        int sub = helper(nums, target, i + 1, currSum - nums[i], offset);

        return dp[i][currSum + offset] = add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for(int& num : nums) {
            sum += num;
        }

        dp.resize(n+1, vector<int>(2*sum + 1, -1));
        return helper(nums, target, 0, 0, sum);
    }
};