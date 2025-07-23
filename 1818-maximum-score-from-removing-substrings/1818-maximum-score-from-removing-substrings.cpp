class Solution {
public:
    int remove(string& s, int val, char ch1, char ch2) {
        stack<char>st;
        int res = 0;
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if(!st.empty() && ch == ch2 && st.top() == ch1) {
                st.pop();
                res += val;
            }
            else{
                st.push(ch);
            }
        }


        s = "";
        while(!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());

        return res;
    }
    int maximumGain(string s, int x, int y) {
        if(x > y) {
            return remove(s, x, 'a', 'b') + remove(s, y, 'b', 'a');
        }

        return remove(s, y, 'b', 'a') + remove(s, x, 'a', 'b');
    }
};