class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        vector<int>vec;
        unordered_map<int, int>map;
        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i] - i;
            vec.push_back(curr);
        }
        long long res = 0;
        for(int i = 0; i < vec.size(); i++){
            res += (i - map[vec[i]]);
            map[vec[i]]++;
        }

        return res;
    }
};