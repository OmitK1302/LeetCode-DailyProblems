class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<int>& arr, int i, int currSum, int sum) {
        if(currSum == sum) return 1;
        if(i == arr.size()) {
            return 0;
        }
        
        if(currSum > sum) {
            return 0;
        }
        
        if(dp[currSum][i] != -1) {
            return dp[currSum][i];
        }
        
        dp[currSum][i] = (helper(arr, i+1, currSum + arr[i], sum) || helper(arr, i+1, currSum, sum));
        return dp[currSum][i];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int& num : nums) {
            sum += num;
        }


        if(sum % 2 != 0) return false;
        dp.resize(sum/2, vector<int>(nums.size(), -1));
        return helper(nums, 0, 0, sum/2) == 1;
    }
};