class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<long long>preReq;
        preReq.push_back(0);

        for(int i = 1; i < nums.size(); i++) {
            long long curr = ((long long)(nums[i] - nums[i-1]) * i) + preReq[i-1];
            preReq.push_back(curr);
        }

        int j = 0;
        int res = 1;
        for(int i = 1; i < nums.size(); i++) {
            while(preReq[i] - preReq[j] - ((long long)(nums[i] - nums[j]) * j) > k) {
                j++;
            }

            res = max(res, i-j+1);
        }

        return res;
    }
};