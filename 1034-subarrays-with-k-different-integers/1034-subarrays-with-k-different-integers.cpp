class Solution {
public:
    int helper(vector<int>& nums, int k) {
        unordered_map<int, int>map;
        int count = 0;
        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            map[nums[right]] += 1;

            while(map.size() > k){
                map[nums[left]] -= 1;
                if(map[nums[left]] == 0){
                    map.erase(nums[left]);
                }
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
        // return helper(nums, k);
        return helper(nums, k-1);
    }
};