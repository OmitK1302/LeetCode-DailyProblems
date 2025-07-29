class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) {
                if(nums[i+1] < nums[i]) return 0;
            }
            else if(i == nums.size() - 1 && nums[i] > nums[i-1]) return i; 
            else if((nums[i-1] < nums[i]) && (nums[i+1] < nums[i])) return i;
        }
        return 0;
    }
};