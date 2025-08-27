class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<bool>prev(n, false);
        vector<bool>next(n, false);

        int minVal = nums[0];
        int maxVal = nums[n-1];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > minVal) {
                prev[i] = true;
            }
            else{
                minVal = nums[i];
            }

            if(nums[n-i-1] < maxVal) {
                next[n-i-1] = true;
            }
            else{
                maxVal = nums[n-i-1];
            }
        }


        for(int i = 1; i < n-1; i++) {
            if(prev[i] && next[i]) return true;
        }

        return false;
    }
};