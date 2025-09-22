class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int>mp;
        int mxFreq = 0;
        for(int& num : nums) {
            mp[num]++;
            mxFreq = max(mxFreq, mp[num]);
        }

        int cnt = 0;
        for(auto& it : mp) {
            if(it.second == mxFreq) {
                cnt += mxFreq;
            }
        }

        return cnt;
    }
};