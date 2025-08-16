class Solution {
public:
    string helper(int n) {
        if(n == 1) return "1";
        string curr = helper(n-1);
        string res;
        for(int i = 0; i < curr.length(); i++) {
            int j = i + 1;
            int cnt = 1;
            while(j < curr.length() && curr[j] == curr[i]) {
                cnt++;
                j++;
            }
            res += to_string(cnt);
            res += curr[i];
            i=j-1;
        }
        cout<<res<<endl;
        return res;
    }
    string countAndSay(int n) {
        return helper(n);
    }
};