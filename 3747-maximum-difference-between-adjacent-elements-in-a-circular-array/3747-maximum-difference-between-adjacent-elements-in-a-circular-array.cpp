class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int res = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(i == nums.size() - 1){
                res = max(res, abs(nums[i] - nums[0]));
                continue;
            }
            res = max(res, abs(nums[i] - nums[i + 1]));
        }

        return res;
    }
};