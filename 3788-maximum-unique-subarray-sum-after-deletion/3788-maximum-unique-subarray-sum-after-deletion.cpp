class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, int>mp;
        int res = 0;
        for(int& num : nums) {
            if(num > 0 && !mp.count(num)) {
                res += num;
                mp[num]++;
            }
        }

        int res2 = INT_MIN;
        for(int& num : nums) {
            if(num >= 0) return res;
            res2 = max(res2, num);
        }
        return res2;
    }
};