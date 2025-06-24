class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0, maxCurrReach = 0;
        int jump = 0;
        if(nums.size() == 1) return 0;
        for(int i = 0; i < nums.size(); i++) {
            maxReach = max(maxReach, nums[i] + i);

            if(i == maxCurrReach) {
                jump++;
                maxCurrReach = maxReach;

                if(maxReach >= nums.size() - 1) break;
            }
        }

        return jump;














        // int maxReach = 0, maxCurrReach = 0;
        // int jump = 0;
        // for(int i = 0; i < nums.size() - 1; i++) {
        //     maxReach = max(maxReach, nums[i] + i);

        //     if(i == maxCurrReach) {
        //         jump++;
        //         maxCurrReach = maxReach;

        //         if(maxCurrReach >= nums.size() - 1) break;
        //     }
        // }

        // return jump;
    }
};