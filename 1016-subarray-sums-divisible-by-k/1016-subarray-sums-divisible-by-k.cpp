class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>prefixRem;
        prefixRem.push_back(0);
        int sum = 0;
        for(int num : nums){
            sum += num;
            int temp = sum % k;
            temp = (temp < 0) ? temp + k : temp;
            prefixRem.push_back(temp);
        }

        int count = 0;
        unordered_map<int, int>map;
        for(int num : prefixRem){
            if(map.contains(num)){
                count += map[num];
            }
            map[num] += 1;
        }

        return count;

    }

    
};