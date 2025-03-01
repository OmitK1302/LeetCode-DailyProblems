class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1]){
                nums[i] = 2 * nums[i];
                nums[i + 1] = 0;
            }
        }

        vector<int>res;
        for(int& num : nums){
            if(num != 0){
                res.push_back(num);
            }
        }

        for(int i = res.size(); i < nums.size(); i++){
            res.push_back(0);
        }

        return res;
    }
};