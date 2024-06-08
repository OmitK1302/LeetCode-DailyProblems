class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int>prefixSumMod;
        prefixSumMod.push_back(0);
        int sum = 0;
        for(int num : nums){
            sum += num;
            prefixSumMod.push_back(sum % k);
        }

        unordered_map<int, int>map;
        for(int i = 0; i < prefixSumMod.size(); i++){
            if(map.contains(prefixSumMod[i])){
                if(i - map[prefixSumMod[i]] > 1) return true;
            }
            else{
                map[prefixSumMod[i]] = i;
            }
        }

        return false;
    }
};