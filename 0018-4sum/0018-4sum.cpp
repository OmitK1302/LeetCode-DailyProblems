class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }

    vector<vector<int>> kSum(vector<int>& nums, long long target, int start, int k) {
        vector<vector<int>> res;
        if (start == nums.size()) {
            return res;
        }
        long long average_value = target / k;
        if (nums[start] > average_value || average_value > nums.back()) {
            return res;
        }

        if (k == 2) {
            return twoSum(nums, target, start);
        }

        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                vector<vector<int>>temp = kSum(nums, static_cast<long long>(target) - nums[i], i + 1, k - 1);
                for (vector<int>& subset : temp) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset), end(subset));
                }
            }
        }

        return res;
    }

    vector<vector<int>> twoSum(vector<int>& nums, long long target, int start) {
        vector<vector<int>> res;
        int low = start, high = int(nums.size()) - 1;

        while (low < high) {
            int curr_sum = nums[low] + nums[high];
            if (curr_sum < target || (low > start && nums[low] == nums[low - 1])) {
                low++;
            } else if (curr_sum > target ||
                       (high < nums.size() - 1 && nums[high] == nums[high + 1])) {
                high--;
            } else {
                res.push_back({nums[low++], nums[high--]});
            }
        }

        return res;
    }
};