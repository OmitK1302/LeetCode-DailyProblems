class Solution {
public:
    int hIndex(vector<int>& cit) {
        // return citations[0];
        sort(cit.rbegin(), cit.rend());
        int res = 0;
        for(int i = 1; i <= cit.size(); i++) {
            if(cit[i-1] >= i) {
                res = i;
            }
        }

        return res;
    }
};