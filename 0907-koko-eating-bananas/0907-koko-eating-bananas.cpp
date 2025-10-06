class Solution {
public:
    bool possible(int m, vector<int>& piles, int h) {
        for(auto& it : piles) {
            if(it <= m) {
                h--;
            }
            else{
                h -= ((it + m - 1) / m);
            }
        }

        return h >= 0;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 0;
        for(int& num : piles) {
            // l = min(l, num);
            r = max(r, num);
        }

        while(l <= r) {
            int mid = l + ((r - l) / 2);

            if(possible(mid, piles, h)) {
                r = mid - 1;
            }            
            else{
                l = mid + 1;
            }
        }

        return l;
    }
};