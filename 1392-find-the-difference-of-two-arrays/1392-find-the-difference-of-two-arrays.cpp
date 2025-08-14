class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mp1;
        unordered_map<int, int>mp2;
        vector<unordered_set<int>>res(2);
        
        for(int& num : nums1) {
            mp1[num]++;
        }

        for(int& num : nums2) {
            mp2[num]++;
        }

        for(int& num : nums1) {
            if(!mp2.count(num)) {
                res[0].insert(num);
            }
        }

        for(int& num : nums2) {
            if(!mp1.count(num)) {
                res[1].insert(num);
            }
        }

        vector<vector<int>>result(2);
        for(auto& it : res[0]) {
            result[0].push_back(it);
        }

        for(auto& it : res[1]) {
            result[1].push_back(it);
        }
        return result;
    }
};