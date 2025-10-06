class Solution {
    bool isPossible(int mid, vector<int>& bloomDay, int m, int k) {
        int tempk = k;
        int cnt = 0;
        for(auto& it : bloomDay) {
            if(it > mid) {
                tempk = k;
                continue;
            }

            tempk--;
            if(tempk == 0) {
                cnt++;
                tempk = k;
            }
        }

        return cnt >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(((long long)m * k) > bloomDay.size()) return -1;

        int l = 0, r;
        for(auto& it : bloomDay) {
            r = max(r, it);
        }

        while(l <= r) {
            int mid = l + ((r - l) / 2);

            if(isPossible(mid, bloomDay, m, k)) {
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return r + 1;
    }
};