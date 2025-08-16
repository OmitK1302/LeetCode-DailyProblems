class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 500001;
        for(int i = 1; i < nums.size()-1; i++) {
            int l = i-1, r = i+1;        
            while(l >= 0 && r < nums.size()) {
                int curr = nums[i] + nums[l] + nums[r];
                if(abs(target - curr) < abs(res - target)) {
                    res = curr;
                }

                if(curr == target) return target;
                else if(curr > target) {
                    l--;
                }
                else {
                    r++;
                }
            }
        }

        return res;
    }
};