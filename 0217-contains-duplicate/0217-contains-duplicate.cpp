class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int>map;

        for(int& num : nums){
            if(map[num]) return true;

            map[num]++;
        }
        return false;
    }
};