class Solution {
public:
    int countHillValley(vector<int>& nums) {
        // int clLeft = 0;
        int n = nums.size();
        vector<int>clRight(n, 0);
        vector<int>clLeft(n, 0);
        int res = 0;
        
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] != nums[i+1]) {
                clRight[i] = nums[i+1];
            }
            else{
                clRight[i] = clRight[i+1];
            }
        }
        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i-1]) {
                clLeft[i] = nums[i-1];
            }
            else{
                clLeft[i] = clLeft[i-1];
            }
        }

        for(int i = 1; i < n-1; i++) {
            int l = clLeft[i];
            int r = clRight[i];
            int num = nums[i];

            if(l > 0 && r > 0 && num != nums[i-1]) {
                if((l > num && r > num) || (l < num && r < num)) {
                    res++;
                }
            }
        }
        return res;
    }
};