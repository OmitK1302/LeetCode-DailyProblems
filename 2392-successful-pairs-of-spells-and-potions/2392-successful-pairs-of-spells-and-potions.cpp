class Solution {
public:
    int bSearch(vector<int>& potions, long long val) {
        int l = 0;
        int r = potions.size() - 1;
        int res = potions.size(); 

        while (l <= r) {
            int mid = (l + r) / 2;
            if ((long long)potions[mid] >= val) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;

        for (int spell : spells) {
            long long val = (success + spell - 1) / spell; 
            int idx = bSearch(potions, val);
            res.push_back(potions.size() - idx);
        }

        return res;
    }
};
