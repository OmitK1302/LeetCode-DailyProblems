class Solution {
public:
    int maxOperations(string s) {
        int res = 0;
        int consec1 = 0;
        for(int i = 0; i < s.size(); i++) {
            int cnt1 = 0;
            while(i < s.size() && s[i] == '1') {
                cnt1++;
                i++;
            }
            bool cnt0 = false;
            while(i < s.size() && cnt1 > 0 && s[i] == '0') {
                // cnt0++;
                cnt0 = true;
                i++;
            }

            consec1 += cnt1;
            res += cnt0 ? consec1 : 0;
            cout<<res<<" ";
            if(cnt0) i--;
        }

        return res;
    }
};