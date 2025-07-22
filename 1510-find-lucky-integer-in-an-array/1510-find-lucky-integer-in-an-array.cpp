class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int>map;
        for(int& num : arr) {
            map[num]++;
        }

        int res = -1;
        for(auto& it : map) {
            if(it.second == it.first) {
                res = max(res, it.first);
            }
        }
        return res;
    }
};