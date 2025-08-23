class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int, greater<int>>mp;


        int maxVal = INT_MIN;
        // int currSum = 0;
        int n = nums.size();
        for(int i = 0; i < min(n, k); i++) {
            mp[nums[i]]++;
            maxVal = max(maxVal, nums[i]);
        }

        if(k == nums.size()) {
            return {maxVal};
        }

        vector<int>res;
        res.push_back(maxVal);

        int l = 0;
        int r = k;
        int strt = 0;
        while(r < nums.size()) {
            mp[nums[r]]++;
            mp[nums[l]]--;

            if(mp[nums[l]] == 0) mp.erase(nums[l]);

            auto it = mp.begin();
            res.push_back(it -> first);

            r++;
            l++;
        }

        return res;
    }
};