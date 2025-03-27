class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>map;
        map[0] = 1;
        int res = 0;
        int currSum = 0;

        for(int& num : nums) {
            currSum += num;
            if(map.count(currSum - k)){
                res += map[currSum - k];
            }
            map[currSum]++;
        }

        return res;
    }
};