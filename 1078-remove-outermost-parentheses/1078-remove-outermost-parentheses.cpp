class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        int temp = 0;
        string res;
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if(ch == ')') {
                open--;
            }
            else{
                open++;
            }


            if(open == 0) {
                res += s.substr(temp+1, i - temp - 1);
                temp = i+1;
            }
        }

        return res;

    }
};