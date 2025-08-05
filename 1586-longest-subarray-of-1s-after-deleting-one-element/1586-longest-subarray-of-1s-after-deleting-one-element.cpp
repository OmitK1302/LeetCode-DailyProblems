class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        int res = 0;
        for(r = 0; r < nums.size(); r++) {
            if(nums[r] == 0) {
                cnt++;
            }
            while(cnt == 2) {
                if(nums[l] == 0) {
                    cnt--;
                }
                l++;
            }
            res = max(res, r - l + 1);

        }

        return res == 0 ? 0 : res - 1;
    }
};