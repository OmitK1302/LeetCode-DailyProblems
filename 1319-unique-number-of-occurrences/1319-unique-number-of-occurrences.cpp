class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>mp;
        unordered_map<int, int>freq;

        for(int& num : arr) {
            mp[num]++;
        }

        for(auto& it : mp) {
            if(freq.count(it.second)) return false;
            freq[it.second] = it.first;
        }

        return true;
    }
};