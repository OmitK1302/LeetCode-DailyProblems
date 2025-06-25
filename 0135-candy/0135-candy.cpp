class Solution {
public:
    int candy(vector<int>& ratings) {
        // int curr = 1;
        // int res = 1;
        int n = ratings.size();

        vector<int>vals(n, 1);

        for(int i = 1; i < n; i++) {
            if(ratings[i-1] < ratings[i]) {
                vals[i] = vals[i-1] + 1;
            }
        }

        for(int i = n-2; i >= 0; i--) {
            if(ratings[i+1] < ratings[i]) {
                vals[i] = max(vals[i], vals[i+1] + 1);
            }
        }

        int ans = 0;
        for(int& val : vals) {
            ans += val;
        }

        return ans;
    }
};