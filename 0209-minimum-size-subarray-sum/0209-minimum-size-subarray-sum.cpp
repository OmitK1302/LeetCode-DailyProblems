class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int currSum = 0;
        int res = 1e6;

        for(int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            bool erased = false;

            while(currSum >= target) {
                currSum -= nums[l];
                l++;
                erased = true;
            }

            if(erased) res = min(res, i-l+2);
        }
        // unordered_map<int, int> mp;
        // int currSum = 0;
        // for(int i = 0; i < nums.size(); i++) {
        //     currSum += nums[i];
        //     if(mp.count(currSum - target)) {
        //         res = min(res, i - mp[currSum - target]);
        //     }
        //     mp[currSum] = i;
        // }

        return res == 1e6 ? 0 : res;
    }
};