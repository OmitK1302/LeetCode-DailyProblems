class Solution {
    bool poss(vector<int>& nums, int mid, int h) {
        int res = 0;
        for(auto& it : nums) {
            res += ((it + mid - 1) / mid);
        }

        return res <= h;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r;

        for(auto& it : nums) {
            r = max(r, it);
        }

        while(l <= r) {
            int mid = l + ((r - l) / 2);
            if(poss(nums, mid, threshold)) {
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return r+1;
    }
};