class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size()) return "0";

        stack<char>st;
        for(int i = 0; i < num.size(); i++) {
            while(k > 0 && (!st.empty()) && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        string str;
        while(!st.empty()) {
            str += st.top();
            st.pop();
        }

        // return str;
        reverse(str.begin(), str.end());
        while(k--) {
            str.pop_back();
        }

        while(str != "0" && str[0] == '0') {
            str.erase(0, 1);
        }

        // if(str.size() = 0) return "0";

        // reverse(str.begin(), str.end());
        return str;
    }
};