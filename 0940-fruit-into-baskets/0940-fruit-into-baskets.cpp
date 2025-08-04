class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int>mp;
        int curr = 0;
        int l = 0;
        int res = 0;
        for(int i = 0; i < fruits.size(); i++) {
            while(mp.size() == 2 && !mp.count(fruits[i])) {
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }
                l++;
                curr--;
            }

            mp[fruits[i]]++;
            curr++;
            res = max(curr, res);
        }
        return res;
    }
};