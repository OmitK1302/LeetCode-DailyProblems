class Solution {
public:
    vector<vector<int>>res;
    void solve(vector<int>& nums, int k, int currVal, int currSum, vector<int>& curr) {
        if(currSum == k) {
            res.push_back(curr);
            return;
        }

        for(int i = currVal; i < nums.size(); i++) {
            int num = nums[i];
            if(currSum + num <= k) {
                curr.push_back(num);
                solve(nums, k, i, currSum + num, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        solve(candidates, target, 0, 0, curr);
        
        // sort(res.begin(), res.end());
        return res;
    }
};