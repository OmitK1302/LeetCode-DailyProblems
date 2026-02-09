class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int el1 = INT_MAX, el2 = INT_MAX;
    
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] <= el1) {
                el2 = el1;
                el1 = nums[i];
            }
            else if(nums[i] < el2) {
                el2 = nums[i];
            }
        }

        return nums[0] + el1 + el2;
    }
};