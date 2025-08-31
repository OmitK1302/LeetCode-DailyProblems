class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int, int>mp;
        for(auto& it : friends) {
            mp[it] = 1;
        }

        vector<int>res;
        for(auto& it : order) {
            if(mp.count(it)) {
                res.push_back(it);
            }
        }

        return res;
    }
};