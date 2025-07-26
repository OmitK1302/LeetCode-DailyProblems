class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>res;
        int j = 0;
        int k = n;
        for(int i =0; i < nums.size(); i+=2) {
            res.push_back(nums[j++]);
            res.push_back(nums[k++]);
        }
        return res;
    }
};