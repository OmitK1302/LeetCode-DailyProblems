class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int>map;

        for(int& num : nums){
            if(num != 0){
                map[num] = 1;
            }
        }

        return map.size();
    }
};