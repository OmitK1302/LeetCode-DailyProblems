class Solution {
public:
    int findLHS(vector<int>& nums) {
        int left = 0;
        int right = 0;

        // int maxEl = nums[left];
        // int right = nums[right];
        // unordered_map<int, int>map;
        sort(nums.begin(), nums.end());
        // int res = INT_MIN;
        int maxlen = 0;
        while(left < nums.size()) {
            while(right < nums.size() && nums[right] - nums[left] <= 1) {
                if(nums[right] - nums[left] == 1) {
                    maxlen = max(maxlen, right-left+1);
                }
                right++;
            }
            left++;
        }
        

        return maxlen;
        
    }
};