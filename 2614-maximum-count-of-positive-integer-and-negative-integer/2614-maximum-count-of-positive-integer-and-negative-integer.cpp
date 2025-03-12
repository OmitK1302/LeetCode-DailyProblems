class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                return max(res, int(nums.size() - i));
            }
            else if(nums[i] == 0){
                continue;
            }
            res++;

        }

        return (nums[nums.size() - 1] == 0) ? res : nums.size();
    }
};